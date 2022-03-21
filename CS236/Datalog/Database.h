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
	
	// I thought this would fix my problem, but it's not
	int get_family_index(string name){
		for(unsigned int i = 0; i < family.size(); i++){
			if(name == family.at(i).get_name()){
				return i;
			}
		}
		return -1;
	}

	Relation& get_relation(string name){
		for(unsigned int i = 0; i < family.size(); i++){
			if(name == family.at(i).get_name()){
				return family.at(i);
			}
		}
		return family.at(0);
	}

	Predicate get_scheme(string name){
		vector<Predicate> schemes = program.get_schemes();
		for(Predicate s : schemes){
			if(s.get_name() == name){
				return s;
			}
		}
		return schemes.at(0);
	}

	// loop through the rules adding tuples to the relations as needed.
	// terminate when no new tuples are added to any relation in the family.
	string parse_rules(){
		stringstream out;
		bool done;
		vector<Relation> rule_relations;
		vector<string> cols;
		int counter = 0;

		out << "Rule Evaluation" << endl;

		// loop through the rules, adding tuples to the relations
		// until no relation changes
		do{
			// begin with done as true
			// if a new tuple is added, turn false
			done = true;
			
			// for each rule in the program
			for(Rule rule : program.get_rules()){
				out << rule.toString() << endl;
				Predicate head = rule.get_head();
				
				// evaluate the body of the rule, pushing back the
				// evaluated arguments to the rule relations vector
				for(Predicate arg : rule.get_body()){
					rule_relations.push_back(evaluate(arg).first);
				}

				// while we have more than one relation in the vector
				// join the back with the front and pop the back
				while(rule_relations.size() > 1){
					Relation back = rule_relations.back();
					rule_relations.pop_back();
					rule_relations[0] = rule_relations.at(0).join(back);
				}


				// for ease of readability, create new relation result
				// and clear the rule relations vector for better(ish) spatial complexity
				Relation result = rule_relations.at(0);
				rule_relations.clear();

				
				// for each parameter in the head
				// push back its string to the list of columne to project
				for(Parameter param : head.get_parameters()){
					cols.push_back(param.toString());
				}


				// find the projection
				result = result.projection(cols);


				// get the appropriate relation to add to
				// using get_relation()
				Relation& to_add_to = get_relation(head.get_name());
				Predicate scheme_in_question = get_scheme(head.get_name());
				vector<string> new_scheme;
				for(Parameter p : scheme_in_question.get_parameters()){
					new_scheme.push_back(p.toString());
				}

				// add each tuple to the relation, checking to see if it is actually added
				// if it is, set done to false, there are more tuples to evaluate
				// and add the tuple's toString to the
				for(Tuple t : result.get_tuples()){
					if(to_add_to.add_tuple(t)){
						out << "  " << t.toString(new_scheme) << endl;
						done = false;
					}
				}
				// clear the cols for the next pass through
				cols.clear();
			}

			// up the counter by one
			counter++;
		}while(!done);
		out << "\nSchemes populated after " << counter << " passes through the Rules." << endl << endl;
		return out.str();
	}

	// evaluates the specified query and returns the resulting relation in a pair
	// with a boolean for whether the query contained a variable
	pair<Relation,bool> evaluate(Predicate query){
		bool has_variable = false;
		Relation eval = get_relation(query.get_name());


		vector<string> old;
		vector<string> rename;
		vector<int> ignore;
		for(unsigned int i = 0; i < query.get_parameters().size(); i++){
			Token next = query.get_parameters().at(i).get_value();
			if(next.get_type() == STRING){
				ignore.push_back(i);
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


		if(has_variable){
			eval = eval.rename(old, rename);
			eval = eval.projection(rename,ignore);
		}
		pair<Relation, bool> p(eval, has_variable);
		return p;
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
	}

	string evaluate_queries(){
		stringstream out;
		out << "Query Evaluation" << endl;
		for(Predicate query : program.get_queries()){

			out << query.toString() << "? ";
			pair<Relation,bool> eval_var = evaluate(query);
			Relation eval = eval_var.first;
			bool has_variable = eval_var.second;
			
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

	string evaluate_rules(){
		// I think this is more elegant, but the spec says to print out each rule evaluation as it happens
		// stringstream out;
		// out << "Rule Evaluation" << endl;
		// for(Rule rule : program.get_rules()){
		// 	out << rule.toString() << endl;
		// 	Predicate head = rule.get_head();
		// 	Relation eval = evaluate(head);
		// 	out << eval.toString();
		// }
		// out << "\nSchemes populated after " << num_passes << " passes through the Rules." << endl << endl;
		// return out.str();
		return parse_rules();
	}

	string evaluate_all(){
		return evaluate_rules() + evaluate_queries();
	}
	
	vector<Relation> get_relations() {return family;}
	bool get_success() {return success;}
};