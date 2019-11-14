#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <sstream>
#include <regex>
#include <windows.h>

int main();
void compute(std::string _command);
void indexer(std::string _filename);
void indexDir(std::string _dirname);
std::string listenCommand();
void run(int _id, std::string _functions, std::string _output, std::string _query);