#include "Scanner.h"

Token Scanner::scanToken() {
	tokenType type;
	int size;
	if(input.size() == 0){
		return Token(END, "", line);
	}
	while(isspace(input.at(0))){
		if(input.at(0) == '\n'){
			line++;
		}
		input = input.substr(1);
	}
	switch(input.at(0)){
		case ',':
			type = COMMA;
			size = 1;
			break;
		case '.':
			type = PERIOD;
			size = 1;
			break;
		case '?':
			type = Q_MARK;
			size = 1;
			break;
		case '(':
			type = LEFT_PAREN;
			size = 1;
			break;
		case ')':
			type = RIGHT_PAREN;
			size = 1;
			break;
		case ':':
			size = scanColon();
			if(size == 1){
				type = COLON;
			}else{
				type = COLON_DASH;
			}
			break;
		case '*':
			type = MULTIPLY;
			size = 1;
			break;
		case '+':
			type = ADD;
			size = 1;
			break;
		case '\'':
			type = STRING;
			size = scanString();
			if(size == 1){
				type = UNDEFINED;
			}
			break;
		case '#':
			type = COMMENT;
			size = scanComment();
			break;
		default:
			size = scanID();
			if(input.substr(0,size) == "Schemes"){
				type = SCHEMES;
			}else if(input.substr(0,size) == "Facts"){
				type = FACTS;
			}else if(input.substr(0,size) == "Rules"){
				type = RULES;
			}else if(input.substr(0,size) == "Queries"){
				type = QUERIES;
			}else if(!isalpha(input.at(0))){
				type = UNDEFINED;
			}else{
				type = ID;
			}
	}
	string value = input.substr(0, size);
	if(type == STRING && value.back() != '\''){
		type = UNDEFINED;
	}
	input = input.substr(size);
	return Token(type, value, line);
}

// scans ahead to find the end of the string.
// will return the size of the string
// and returns 0 if the eof is reached before string ends
int Scanner::scanString(){
	int size = input.size();
	int counter = 1;
	while(counter < size){
		if(input.at(counter) == '\''){
			return ++counter;
		}
		counter++;
	}
	return counter;
}

int Scanner::scanID(){
	int size = input.size();
	int counter = 1;
	while(counter < size){
		if(!isalnum(input.at(counter))){
			return counter;
		}
		counter++;
	}
	return counter;
}

int Scanner::scanColon(){
	if(input.size() == 1){
		return 1;
	}
	if(input.at(1) == '-'){
		return 2;
	}else{
		return 1;
	}
}

int Scanner::scanComment(){
	int size = input.size();
	int counter = 1;
	while(counter < size){
		if(input.at(counter) == '\n'){
			return counter;
		}
		counter++;
	}
	return counter;
}

pair<vector<Token>, int> Scanner::Scan(){
	vector<Token> tokens;
	bool cont = true;
	while(cont){
		Token t = scanToken();
		if(t.get_type() == END){
			cont = false;
		}
		tokens.push_back(t);
	}

	return make_pair(tokens, tokens.size());
}

bool Scanner::readFile(string filename){
	ifstream ifs;
	ifs.open(filename);
	if(!ifs.is_open()){
		return 0;
	}
	stringstream buffer;
	buffer << ifs.rdbuf();
	input = buffer.str();
	line = 1;
	return 1;
}