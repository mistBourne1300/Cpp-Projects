# pragma once
# include <vector>
# include <string>
# include <sstream>
# include <set>
using namespace std;

# include "Relation.h"
# include "Parser.h"

class Database {
private:
	vector<Relation> family;
	Datalog_Program program;
	bool success;

	Relation get_relation(Predicate query){
		for(unsigned int i = 0; i <  family.size(); i++){
			if(query.get_name() == family.at(i).get_name()){
				return family.at(i);
			}
		}
		return family.at(0);
	}

public:
	Database(string filename){
		Parser parser(filename);
		if(!parser.true_parse()){
			family = {};
			success = false;
			return;
		}

		program = parser.get_program();
		for(Predicate scheme : program.get_schemes()){
			vector<string> scheme_names;
			for(Parameter param : scheme.get_parameters()){
				scheme_names.push_back(param.toString());
			}
			Relation new_rel(scheme.get_name(), scheme_names);
			family.push_back(new_rel);
		}

		for(Predicate fact : program.get_facts()){
			// get a vector of strings for the argument
			vector<string> args;
			for(Parameter param : fact.get_parameters()){
				args.push_back(param.toString());
			}
			
			for(unsigned int i = 0; i < family.size(); i++){
				if(fact.get_name() == family.at(i).get_name()){
					Tuple t(args);
					family.at(i).add_tuple(Tuple(args));
					break;
				}
			}
			
		}

	success = true;
	}

	string evaluate(){
		stringstream out;
		for(Predicate query : program.get_queries()){
			bool has_variable = false;
			out << query.toString() << "? ";
			Relation eval = get_relation(query);


			vector<string> old;
			vector<string> rename;
			for(unsigned int i = 0; i < query.get_parameters().size(); i++){
				Token next = query.get_parameters().at(i).get_value();
				if(next.get_type() == STRING){
					eval = eval.select(i, next.get_value());
				} else if (next.get_type() == ID){
					has_variable = true;
					old.push_back(eval.get_scheme().at(i));
					rename.push_back(next.get_value());
				}
			}
			
			// similar select
			for(unsigned int i = 0; i < query.get_parameters().size(); i++){
				Token curr = query.get_parameters().at(i).get_value();
				if(curr.get_type() != ID){continue;}
				vector<int> indices;
				for(unsigned int j = 0; j < query.get_parameters().size(); j++){
					if(curr.get_value() == query.get_parameters().at(j).get_value().get_value()){
						indices.push_back(j);
					}
				}
				eval = eval.select_similar(indices);
			}

			for(unsigned int i = 0; i < old.size(); i++){
			}
			if(has_variable){
				eval = eval.rename(old, rename);
				eval = eval.projector(rename);
			}
			
			
			if(eval.size() > 0){
				out << "Yes(" << eval.size() << ")" << endl;
				if(has_variable){
					out << eval.toString();
				}
			} else{
				out << "No" << endl;
			}
		}
		return out.str();
	}

	vector<Relation> get_relations() {return family;}
	bool get_success() {return success;}
};