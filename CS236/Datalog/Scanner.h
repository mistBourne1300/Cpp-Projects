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
	int scan_string();
	int scan_ID();
	int scan_colon();
	int scan_comment();

public:
	Scanner(string filename){
		read_file(filename);
		line = 1;
	}

	Token scan_token();
	vector<Token> scan();
	bool read_file(string filename);
};