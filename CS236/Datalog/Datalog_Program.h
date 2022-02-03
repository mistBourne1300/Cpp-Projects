# pragma once
# include <sstream>
# include <vector>
# include <iostream>
# include <string>
# include <algorithm>
# include <set>
using namespace std;

# include "Parameter.h"
# include "Token.h"
# include "Predicate.h"
# include "Rule.h"

/*Success!
Schemes(2):
  snap(S,N,A,P)
  HasSameAddress(X,Y)
Facts(2):
  snap('12345','C. Brown','12 Apple','555-1234').
  snap('33333','Snoopy','12 Apple','555-1234').
Rules(1):
  HasSameAddress(X,Y) :- snap(A,X,B,C),snap(D,Y,B,E).
Queries(1):
  HasSameAddress('Snoopy',Who)?
Domain(6):
  '12 Apple'
  '12345'
  '33333'
  '555-1234'
  'C. Brown'
  'Snoopy'*/

class Datalog_Program {
private:
	vector<Predicate> prog_schemes;
	vector<Predicate> prog_facts;
	vector<Rule> prog_rules;
	vector<Predicate> prog_queries;
	// TODO: create domain vector and initialize it inside the initializer funtion
	// the domain is every string in the facts parameters, not anything else. A set should work nicely
	set<string> domain;
public:

	// Datalog_Program(vector<Predicate> s, vector<Predicate> f, vector<Rule> r, vector<Predicate> q/*, vector<Parameter> d*/) : prog_schemes(s), prog_facts(f), prog_rules(r), prog_queries(q){
	// 	// domain = d
	// 	// sort(domain.begin(), domain.end())
	// }

	void initialize(vector<Predicate> s, vector<Predicate> f, vector<Rule> r, vector<Predicate> q/*, vector<Parameter> d*/){
		prog_schemes = s;
		prog_facts = f;
		prog_rules = r;
		prog_queries = q;

		for(int i = 0; i < prog_facts.size(); i++){
			// for each fact
			vector<Parameter> params = prog_facts.at(i).get_parameters();
			for(int j = 0; j < params.size(); j++){
				// for each parameter in fact insert the string of that parameter into the domain
				domain.insert(params.at(j).toString());
			}
		}
	}
	
	string toString(){
		stringstream ss;
		ss << "Schemes(" << prog_schemes.size() << "):\n";
		for(unsigned int i = 0; i < prog_schemes.size(); i++){
			ss << "  " << prog_schemes.at(i).toString() << endl;
		}

		ss << "Facts(" << prog_facts.size() << "):\n";
		for(unsigned int i = 0; i < prog_facts.size(); i++){
			ss << "  " << prog_facts.at(i).toString() << "." << endl;
		}

		ss << "Rules(" << prog_rules.size() << "):\n";
		for(unsigned int i = 0; i < prog_rules.size(); i++){
			ss << "  " << prog_rules.at(i).toString() << "." << endl;
		}

		ss << "Queries(" << prog_queries.size() << "):\n";
		for(unsigned int i = 0; i < prog_queries.size(); i++){
			ss << "  " << prog_queries.at(i).toString() << "?" << endl;
		}

		ss << "Domain(" << domain.size() << "):\n";
		for(set<string>::iterator it = domain.begin(); it != domain.end(); it++){
			ss << "  " << *it << endl;;
		}

		return ss.str();

	}

};

