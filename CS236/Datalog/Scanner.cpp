#include "Scanner.h"

Token Scanner::scan_token() {
	tokenType type;
	int size;
	while(input.size() > 0 && isspace(input.at(0))){
		if(input.at(0) == '\n'){
			line++;
		}
		input = input.substr(1);

	}
	if(input.size() == 0){
		return Token(END, "", line);
	}
	int myline = line;
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
			size = scan_colon();
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
			size = scan_string();
			if(size == 1){
				type = UNDEFINED;
			}
			break;
		case '#':
			type = COMMENT;
			size = scan_comment();
			break;
		default:
			size = scan_ID();
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
	if(type == COMMENT){
		return scan_token();
	}
	return Token(type, value, myline);
}


int Scanner::scan_string(){
	int size = input.size();
	int counter = 1;
	while(counter < size){
		if(input.at(counter) == '\''){
			return ++counter;
		}else if(input.at(counter) == '\n'){
			line++;
		}
		counter++;
	}
	return counter;
}

int Scanner::scan_ID(){
	int size = input.size();
	int counter = 1;
	if(!isalpha(input.at(0))){
		return 1;
	}
	while(counter < size){
		if(!isalnum(input.at(counter))){
			return counter;
		}
		counter++;
	}
	return counter;
}

int Scanner::scan_colon(){
	if(input.size() == 1){
		return 1;
	}
	if(input.at(1) == '-'){
		return 2;
	}else{
		return 1;
	}
}

int Scanner::scan_comment(){
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

vector<Token> Scanner::scan(){
	vector<Token> tokens;
	bool cont = true;
	while(cont){
		Token t = scan_token();
		if(t.get_type() == END){
			cont = false;
		}
		tokens.push_back(t);
	}

	return tokens;
}

bool Scanner::read_file(string filename){
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