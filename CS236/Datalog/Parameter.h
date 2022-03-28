# pragma once
# include <iostream>
# include <sstream>
# include <string>
using namespace std;

# include "Token.h"

class Parameter {
private:
	Token value;

public:
	Parameter(Token v) : value(v){}
	string toString() const {return value.get_value();}
	void set_value(Token v) {value = v;}
	Token get_value() {return value;}
	bool operator<(Parameter& right){
		return this->toString() < right.toString();
	}
	bool operator==(Parameter& right) {
		return this->toString() == right.toString();
	}
};
