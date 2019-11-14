#pragma once

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <regex>
#include <iterator>
#include <future>
#include <filesystem>
//#include <boost/algorithm/string.hpp>

class Index
{
private:
	int nbDoc;
	std::map<std::string, std::vector<std::pair<int, int>>> index;
	std::map<int, int> lengths;
	std::vector<std::future<void>> i_futures;
	std::vector<std::future<void>> vf_xml;
	std::set<std::string> stoplist;
	
public:
	Index(std::string _stoplistfilename);
	void addFile(std::string _filename);
	std::map<std::string, std::vector<std::pair<int, int>>>* getIndex();
	std::vector<std::pair<int, int>> getTerm(std::string _term);
	void run(int _id, std::string _functions, std::string _output, std::string _query);
	void readXmlFiles(std::string _foldername);
};
