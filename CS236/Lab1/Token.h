#pragma once
#include <string>
#include <sstream>

using namespace std;


enum tokenType{
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	COMMENT,
	UNDEFINED,
	END
};

class Token {
private:
	tokenType type;
	string tolkien;
	int line;

public:
	Token(tokenType type, string tolkien, int line) : type(type), tolkien(tolkien), line(line){}
	string toString(){
		stringstream out;
		out << "(" << enum_to_string() << ",\"" << tolkien << "\"," << line << ")";
		return out.str();
	}
	string enum_to_string(){
		switch(type){
			case COMMA: return "COMMA";
			case PERIOD: return "PERIOD";
			case Q_MARK: return "Q_MARK";
			case LEFT_PAREN: return "LEFT_PAREN";
			case RIGHT_PAREN: return "RIGHT_PAREN";
			case COLON: return "COLON";
			case COLON_DASH: return "COLON_DASH";
			case MULTIPLY: return "MULTIPLY";
			case ADD: return "ADD";
			case SCHEMES: return "SCHEMES";
			case FACTS: return "FACTS";
			case RULES: return "RULES";
			case QUERIES: return "QUERIES";
			case ID: return "ID";
			case STRING: return "STRING";
			case COMMENT: return "COMMENT";
			case UNDEFINED: return "UNDEFINED";
			case END: return "END";
		}
	}

	tokenType get_type(){
		return type;
	}
	
};