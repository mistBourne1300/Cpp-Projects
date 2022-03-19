# pragma once
# include <string>
# include <vector>
# include <sstream>
# include <iostream>
using namespace std;

# include "Parameter.h"

class Rule {
private:
	Predicate head;
	vector<Predicate> body;

public:
	Rule(Predicate h): head(h){}

	void add_body(Predicate b) {body.push_back(b);}

	void replace_all(vector<Predicate> b) {body = b;}

	string toString(){
		stringstream ss;
		ss << head.toString() << " :- ";
		unsigned int size = body.size();
		for(unsigned int i = 0; i < size; i++){
			ss << body.at(i).toString();
			if(i < size - 1){
				ss << ",";
			}
		}
		ss << ".";
		return ss.str();
	}

	vector<Predicate> get_body() {return body;}
	Predicate get_head() {return head;}
};