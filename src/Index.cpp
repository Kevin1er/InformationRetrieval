#include "Index.h"

Index::Index(std::string _stoplistfilename)
{
	nbDoc = 0;
	std::string word;
	std::ifstream read(_stoplistfilename);

	for (std::string line; std::getline(read, line);)
	{
		stoplist.insert(line);
	}
}

std::mutex m_index;
std::mutex m_lengths;

static void computeLine(std::map<std::string, std::vector<std::pair<int, int>>>* _index, std::string _line, int _docnum, std::map<int, int>* _lengths, std::set<std::string>* _stoplist)
{
	int length = 0;
	std::string word;
	_line = std::regex_replace(_line, std::regex("[^A-Za-z\s]"), " ");
	std::stringstream ss(_line);
	while (ss >> word)
	{
		length++;
		//boost::to_lower(word);
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (_stoplist->find(word) == _stoplist->end() && word.length() > 2)
		{
			auto pos = _index->find(word);
			if (pos != _index->end())
			{
				if (pos->second.back().first == _docnum)
				{
					//std::unique_lock<std::mutex> lock(m_index);
					pos->second.back().second++;
					//lock.unlock();
				}
				else
				{
					//std::unique_lock<std::mutex> lock(m_index);
					pos->second.push_back(std::pair<int, int>(_docnum, 1));
					//lock.unlock();
				}
			}
			else
			{
				std::vector<std::pair<int, int>> vec;
				std::pair<int, int> value(_docnum, 1);
				vec.push_back(value);
				//std::unique_lock<std::mutex> lock(m_index);
				_index->insert({ word, vec });
				//lock.unlock();
			}
		}
		
	}
	auto posLength = _lengths->find(_docnum);
	if (posLength != _lengths->end())
	{
		//std::lock_guard<std::mutex> lock(m_lengths);
		posLength->second += length;
	}
	else
	{
		//std::lock_guard<std::mutex> lock(m_lengths);
		_lengths->insert({ _docnum, length });
	}
}

/**
 * Function addFile :
 * Use to add a file to an index
 */
void Index::addFile(std::string _filename)
{
	int docnum = 0;
	int length = 0;
	std::string word;
	std::ifstream read(_filename);

	for (std::string line; std::getline(read, line);)
	{
		if (!line.empty()) {
			if (line.find("<doc>") != std::string::npos)
			{
				if (length > 0)
				{
					lengths.insert({ docnum, length });
					length = 0;
				}
				std::regex rx(R"((?:^|\s|>)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s|<))");
				std::smatch match;
				regex_search(line, match, rx);
				docnum = std::stoi(match[1].str());
				nbDoc++;
			}
			else if (line != "</doc>")
			{
				//i_futures.push_back(std::async(std::launch::async, computeLine, &index, line, docnum, &lengths, &stoplist));
				computeLine(&index, line, docnum, &lengths, &stoplist);
			}
		}
	}
	read.close();
	lengths.insert({ docnum, length });
}

std::map<std::string, std::vector<std::pair<int, int>>>* Index::getIndex()
{
	return &index;
}

std::vector<std::pair<int, int>> Index::getTerm(std::string _term)
{
	if (index.count(_term) > 0)
	{
		return index.at(_term);
	}
	return {};
}


static double l__(double _tf)
{
	return 1 + log(_tf);
}

static double s__(double _tf)
{
	return _tf * _tf;
}

static double _t_(int _nbdocs, double _df)
{
	return log((double)_nbdocs / _df);
}

static double _l_(int _nbdocs, double _df)
{
	return log(1 + ((double)_nbdocs / _df));
}

static double _f_(double _df)
{
	return 1 / _df;
}

static double _p_(int _nbdocs, double _df)
{
	return log(((double)_nbdocs - _df) / _df);
}

static double _s_(int _nbdocs, double _df)
{
	return pow(log(((double)_nbdocs + 1) / _df), 2);
}

static double __c(std::string _term, std::map<std::string, int>* _query, int _nbdocs, char _tf, char _idf, std::map<std::string, std::vector<std::pair<int, int>>>* _index)
{
	double sum = 0.0;
	double termWeigth = 0.0;

	std::map<std::string, int>::iterator it_q;
	it_q = _query->begin();
	while (it_q != _query->end())
	{
		double tf = 0.0;
		double idf = 0.0;
		double w = 0.0;
		switch (_tf)
		{
		case 'l':
			tf = l__(it_q->second);
			break;
		case 's':
			tf = s__(it_q->second);
			break;
		default:
			break;
		}

		auto posT = _index->find(it_q->first);
		if (posT != _index->end())
		{
			switch (_idf)
			{
			case 't':
				idf = _t_(_nbdocs, (double)posT->second.size());
				break;
			case 'l':
				idf = _l_(_nbdocs, (double)posT->second.size());
				break;
			case 'f':
				idf = _f_((double)posT->second.size());
				break;
			case 'p':
				idf = _p_(_nbdocs, (double)posT->second.size());
				break;
			case 's':
				idf = _s_(_nbdocs, (double)posT->second.size());
				break;
			default:
				break;
			}

			w = tf * idf;
			if (it_q->first == _term)
				termWeigth = w;
			sum += pow(w, 2);
		}

		it_q++;
	}

	return termWeigth / sqrt(sum);
}

static double __s(std::string _term, std::map<std::string, int>* _query, int _nbdocs, char _tf, char _idf, std::map<std::string, std::vector<std::pair<int, int>>>* _index)
{
	double sum = 0.0;
	double termWeigth = 0.0;

	std::map<std::string, int>::iterator it_q;
	it_q = _query->begin();
	while (it_q != _query->end())
	{
		double tf = 0.0;
		double idf = 0.0;
		double w = 0.0;
		switch (_tf)
		{
		case 'l':
			tf = l__(it_q->second);
			break;
		case 's':
			tf = s__(it_q->second);
			break;
		default:
			break;
		}

		auto posT = _index->find(it_q->first);
		if (posT != _index->end())
		{
			switch (_idf)
			{
			case 't':
				idf = _t_(_nbdocs, (double)posT->second.size());
				break;
			case 'l':
				idf = _l_(_nbdocs, (double)posT->second.size());
				break;
			case 'f':
				idf = _f_((double)posT->second.size());
				break;
			case 'p':
				idf = _p_(_nbdocs, (double)posT->second.size());
				break;
			case 's':
				idf = _s_(_nbdocs, (double)posT->second.size());
				break;
			default:
				break;
			}

			w = tf * idf;
			if (it_q->first == _term)
				termWeigth = w;
			sum += w;
		}

		it_q++;
	}

	return termWeigth / sum;
}

static double __n(std::string _term, double _tfrec, int _nbdocs, char _tf, char _idf, std::map<std::string, std::vector<std::pair<int, int>>>* _index)
{
	double tf = 0.0;
	double idf = 0.0;
	switch (_tf)
	{
	case 'l':
		tf = l__(_tfrec);
		break;
	case 's':
		tf = s__(_tfrec);
		break;
	default:
		tf = _tfrec;
		break;
	}
	auto posT = _index->find(_term);
	if (posT != _index->end())
	{
		switch (_idf)
		{
		case 't':
			idf = _t_(_nbdocs, (double)posT->second.size());
			break;
		case 'l':
			idf = _l_(_nbdocs, (double)posT->second.size());
			break;
		case 'f':
			idf = _f_((double)posT->second.size());
			break;
		case 'p':
			idf = _p_(_nbdocs, (double)posT->second.size());
			break;
		case 's':
			idf = _s_(_nbdocs, (double)posT->second.size());
			break;
		default:
			idf = 1.0;
			break;
		}
	}
	return tf * idf;
}

void Index::run(int _id, std::string _function, std::string _output, std::string _query)
{
	std::map<int, double> scores;
	std::map<std::string, int> query;
	std::map<std::string, int>::iterator it;

	std::stringstream ss(_query);
	std::string word;
	while (ss >> word)
	{
		auto pos = query.find(word);
		if (pos != query.end())
			pos->second++;
		else
			query.insert({ word, 1 });
	}

	it = query.begin();
	while (it != query.end())
	{
		double weight = 0.0;

		switch (_function.at(2))
		{
		case 'c':
			weight = __c(it->first, &query, nbDoc, _function.at(0), _function.at(1), &index);
			break;
		case 's':
			weight = __s(it->first, &query, nbDoc, _function.at(0), _function.at(1), &index);
			break;
		default:
			weight = __n(it->first, it->second, nbDoc, _function.at(0), _function.at(1), &index);
			break;
		}

		auto posT = index.find(it->first);
		if (posT != index.end())
		{
			double idf = 0.0;
			switch (_function.at(1))
			{
			case 't':
				idf = _t_(nbDoc, (double)posT->second.size());
				break;
			case 'l':
				idf = _l_(nbDoc, (double)posT->second.size());
				break;
			case 'f':
				idf = _f_((double)posT->second.size());
				break;
			case 'p':
				idf = _p_(nbDoc, (double)posT->second.size());
				break;
			case 's':
				idf = _s_(nbDoc, (double)posT->second.size());
				break;
			default:
				idf = 1.0;
				break;
			}

			for (std::pair<int, int> pair : posT->second)
			{
				double tf = 0.0;
				switch (_function.at(0))
				{
				case 'l':
					tf = l__(pair.second);
					break;
				case 's':
					tf = s__(pair.second);
					break;
				default:
					tf = (double)pair.second;
					break;
				}
				// Poids pas pris en compte (peut etre remplacer tf*idf -> w
				double s = 0.0;
				
				switch (_function.at(2))
				{
				case 'c':
					s  = __c(it->first, &query, nbDoc, _function.at(0), _function.at(1), &index) * weight;
					break;
				case 's':
					s = __s(it->first, &query, nbDoc, _function.at(0), _function.at(1), &index) * weight;
					break;
				default:
					s = __n(it->first, it->second, nbDoc, _function.at(0), _function.at(1), &index) * weight;
					break;
				}
				auto p = scores.find(pair.first);
				if (p != scores.end())
					p->second += s;
				else
					scores.insert({ pair.first, s });
			}
		}
		it++;
	}

	std::map<double, int> scores_reverse;
	std::map<int, double>::iterator it2 = scores.begin();
	while (it2 != scores.end())
	{
		it2->second /= lengths.find(it2->first)->second;
		scores_reverse.insert({ it2->second, it2->first });
		it2++;
	}

	std::map<double, int>::reverse_iterator it3 = scores_reverse.rbegin();
	std::ofstream output;
	output.open(_output, std::ios::app);
	int n = 1;
	while (it3 != scores_reverse.rend() && n <= 1500)
	{
		output << _id << " Q0 " << it3->second << " " << n << " " << it3->first << " KevinDanRedhaLatifa /article[1]\n";
		it3++;
		n++;
	}
	output.close();
}

static void readXml(std::string _filename, std::map<std::string, std::vector<std::pair<int, int>>>* _index, std::map<int, int>* _lengths, std::set<std::string>* _stoplist)
{
	std::regex rx("[0-9]+");
	std::smatch match;
	regex_search(_filename, match, rx);
	int docnum = std::stoi(match[0].str());
	std::string word;
	std::ifstream read(_filename);

	for (std::string line; std::getline(read, line);)
	{
		line = std::regex_replace(line, std::regex("[<][^>]*[>]"), "");
		if (!line.empty()) {
			computeLine(_index, line, docnum, _lengths, _stoplist);
		}
	}
	read.close();
}

void Index::readXmlFiles(std::string _foldername)
{
	for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(_foldername))
	{
		if (!dirEntry.is_directory())
		{
			//vf_xml.push_back(std::async(std::launch::async, readXml, dirEntry.path().string(), &index, &lengths, &stoplist));
			readXml(dirEntry.path().string(), &index, &lengths, &stoplist);
			nbDoc++;
		}
	}
}
