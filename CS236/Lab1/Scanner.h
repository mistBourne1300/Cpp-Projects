#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

#include "Token.h"

class Scanner {
private:
	string input;
	int line;
	int scanString();
	int scanID();
	int scanColon();
	int scanComment();

public:
	Scanner(string input = "") : input(input), line(1){}
	Token scanToken();
	pair<vector<Token>, int> Scan();
	bool readFile(string filename);
};