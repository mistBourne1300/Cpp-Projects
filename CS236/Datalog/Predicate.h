# pragma once
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
using namespace std;

# include "Parameter.h"


class Predicate {
private:
	string name;
	vector<Parameter> parameters;
public:
	Predicate(string name) : name(name){}

	string get_name() const {return name;}

	vector<Parameter> get_parameters() {return parameters;}

	void add_parameter(Parameter p) {parameters.push_back(p);}

	void add_all(vector<Parameter> p) {parameters = p;}

	string toString() const{
		stringstream ss;
		ss << name << "(";
		unsigned int size = parameters.size();
		for(unsigned int i = 0; i < size; i++){
			ss << parameters.at(i).toString();
			if(i < size - 1){
				ss << ",";
			}
		}
		ss << ")";
		return ss.str();
	}

};