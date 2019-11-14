#include "RI.h"
#include "Index.h"


bool quit = false;
Index index("../StopWord.txt");

int main()
{
	while (!quit)
	{
		std::cout << "> ";
		compute(listenCommand());
	}
}

std::string listenCommand()
{
	std::string command;
	std::getline(std::cin, command);
	return command;
}

void compute(std::string _command)
{
	if (_command == "eval")
	{
		run(2009011, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "web link network analysis");
		run(2009074, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "ltn", "KevinDanRedhaLatifa_01_01_ltn_articles_stopwords.txt", "operating system mutual exclusion");
	
		run(2009011, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "web link network analysis");
		run(2009074, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "ltc", "KevinDanRedhaLatifa_01_02_ltc_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lts", "KevinDanRedhaLatifa_01_03_lts_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lsc", "KevinDanRedhaLatifa_01_04_lsc_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lss", "KevinDanRedhaLatifa_01_05_lss_articles_stopwords.txt", "operating system mutual exclusion");
	}
	else if (_command == "evalxml")
	{
		run(2009011, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "web link network analysis");
		run(2009074, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "ltn", "KevinDanRedhaLatifa_02_01_ltn_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "web link network analysis");
		run(2009074, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "ltc", "KevinDanRedhaLatifa_02_02_ltc_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lts", "KevinDanRedhaLatifa_02_03_lts_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lsc", "KevinDanRedhaLatifa_02_04_lsc_articles_stopwords.txt", "operating system mutual exclusion");

		run(2009011, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "olive oil health benefit");
		run(2009036, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "notting hill film actors");
		run(2009067, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "probabilistic models in information retrieval");
		run(2009073, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "web link network analysis");
		run(2009074, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "web ranking scoring algorithm");
		run(2009078, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "supervised machine learning algorithm");
		run(2009085, "lss", "KevinDanRedhaLatifa_02_05_lss_articles_stopwords.txt", "operating system mutual exclusion");
	}
	else if (std::regex_match(_command, std::regex("(index )(.*)")))
	{
		std::istringstream iss(_command);
		std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
			std::istream_iterator<std::string>());
		if (results.size() < 2)
		{
			std::cout << "Commande incorecte\n" << std::endl;
			return;
		}
		indexer(results.at(1));
	}
	else if (std::regex_match(_command, std::regex("(indexdir )(.*)")))
	{
		std::istringstream iss(_command);
		std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
			std::istream_iterator<std::string>());
		if (results.size() < 2)
		{
			std::cout << "Commande incorecte\n" << std::endl;
			return;
		}
		indexDir(results.at(1));
	}
	else if (std::regex_match(_command, std::regex("(run )(.*)")))
	{
		std::istringstream iss(_command);
		std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
			std::istream_iterator<std::string>());
		if (results.size() < 5)
		{
			std::cout << "Commande incorecte\n" << std::endl;
			return;
		}
		std::string query;
		for (int i = 4; i < results.size(); i++)
			query.append(results.at(i) + " ");
		run(std::stoi(results.at(1)), results.at(2), results.at(3), query);
	}
	else if (std::regex_match(_command, std::regex("(term )(.*)")))
	{
		std::istringstream iss(_command);
		std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
			std::istream_iterator<std::string>());
		if (results.size() < 2)
		{
			std::cout << "Commande incorecte\n" << std::endl;
			return;
		}
		std::vector<std::pair<int, int>> result = index.getTerm(results.at(1));
		if (result.size() > 0)
		{
			std::cout << "Term \"" << results.at(1) << "\" -> " << std::endl;
			for (std::pair<int, int> p : result)
			{
				std::cout << p.first << " -> " << p.second << std::endl;
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Term \"" << results.at(1) << "\" doesn't exists :(\n" << std::endl;
		}
	}
	else if (_command == "clear")
	{
		system("CLS");
	}
	else if (_command == "quit")
	{
		quit = true;
	}
	else
	{
		std::cout << "Commande inconnue\n" << std::endl;
	}
}

/**
* Indexing function
*/
void indexer(std::string _filename)
{
	std::ifstream is(_filename);
	if (is)
	{
		// Le fichier existe
		std::cout << "Indexing..." << std::endl;
		index.addFile(_filename);
		std::cout << "indexing done :)\n" << std::endl;
	}
	else
	{
		std::cout << "ERREUR : Le fichier \"" << _filename << "\" n'existe pas." << std::endl;
	}
	is.close();
}

void run(int _id, std::string _functions, std::string _output, std::string _query)
{
	index.run(_id, _functions, _output, _query);
}

void indexDir(std::string _dirname)
{
	index.readXmlFiles(_dirname);
}
