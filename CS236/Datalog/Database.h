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
	int num_passes;

	Relation get_relation(string name){
		for(Relation rel : family){
			if(name == rel.get_name()){
				return rel;
			}
		}
		return family.at(0);
	}

	// loop through the rules adding tuples to the relations as needed.
	// terminate when no new tuples are added to any relation in the family.
	int parse_rules(){
		bool done;
		vector<Relation> rule_relations;
		vector<string> cols;
		int counter = 0;

		// loop through the rules, adding tuples to the relations
		// until no relation changes
		do{
			// begin with done as true
			// if a new tuple is added, turn false
			done = true;
			
			// for each rule in the program
			for(Rule rule : program.get_rules()){
				Predicate head = rule.get_head();
				
				// evaluate the body of the rule, pushing back the
				// evaluated arguments to the rule relations vector
				for(Predicate arg : rule.get_body()){
					rule_relations.push_back(evaluate(arg));
				}

				// while we have more than one relation in the vector
				// join the back with the front and pop the back
				while(rule_relations.size() > 1){
					Relation back = rule_relations.back();
					rule_relations.pop_back();
					rule_relations[0] = rule_relations.at(0).join(back);
				}

				// for ease of readability, create new relation result
				// and clear the rule relations vector for better(ish) spatial coplexity
				Relation result = rule_relations.at(0);
				rule_relations.clear();
				
				// for each parameter in the head
				// push back its string to the list of columne to project
				for(Parameter param : head.get_parameters()){
					cols.push_back(param.toString());
				}

				// find the projection then
				// clear the columns for better(ish) spatial complexity
				result = result.projection(cols);
				cols.clear();

				// get the appropriate relation to add to
				// using get_relation()
				Relation to_add_to = get_relation(head.get_name());	

				// add each tuple to the relation, checking to see if it is actually added
				// if it is, set done to false, there are more tuples to evaluate			
				for(Tuple t : result.get_tuples()){
					if(to_add_to.add_tuple(t)){
						done = false;
					}
				}
			}

			// up the counter by one
			counter++;
		}while(!done);
		return counter;
	}

	// evaluates the specified query and returns the resulting relation in a pair
	// with a boolean for whether the query contained a variable
	Relation evaluate(Predicate query){
		bool has_variable = false;
		Relation eval = get_relation(query.get_name());


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
			eval = eval.projection(rename);
		}

		return eval;
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

		// for each fact in the program, add a tuple to the apropriate relation
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
	num_passes = parse_rules();
	}

	string evaluate_queries(){
		stringstream out;
		out << "Query Evaluation" << endl;
		for(Predicate query : program.get_queries()){

			out << query.toString() << "? ";

			Relation eval = evaluate(query);
			// bool has_variable = eval_var.second;
			
			if(eval.size() > 0){
				out << "Yes(" << eval.size() << ")" << endl;
				out << eval.toString();
			} else{
				out << "No" << endl;
			}
		}
		return out.str();
	}

	string evaluate_rules(){
		stringstream out;
		out << "Rule Evaluation" << endl;
		for(Rule rule : program.get_rules()){
			out << rule.toString() << endl;
			Predicate head = rule.get_head();
			Relation eval = evaluate(head);
			out << eval.toString();
		}
		out << "\nSchemes populated after " << num_passes << " passes through the Rules." << endl << endl;
		return out.str();
	}

	string evaluate_all(){
		return evaluate_rules() + evaluate_queries();
	}
	
	vector<Relation> get_relations() {return family;}
	bool get_success() {return success;}
};