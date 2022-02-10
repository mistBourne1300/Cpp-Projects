# pragma once
# include <vector>
# include <string>
using namespace std;

# include "Scanner.h"
# include "include.h"

class Parser{
private:
	vector<Token> tokens;
	Datalog_Program program;
	bool parsed_true;
public:
	Parser(string filename){
		tokens = Scanner(filename).scan();
		// for(unsigned int i = 0; i < tokens.size(); i++){
		// 	cout << tokens.at(i).toString() << endl;
		// }
		parsed_true = parse();
	}

	bool parse(){
		try{
			datalog_program();
		}catch(string msg){
			cout << msg;
			return 0;
		}
		return 1;
	}

	tokenType token_type() const{
		return tokens.at(0).get_type();
	}

	void advance_token(){
		tokens.erase(tokens.begin());
	}

	void throw_error(){
		stringstream ss;
		Token err_token = tokens.at(0);
		ss << "Failure!" << endl << "  " << err_token.toString() << endl;
		throw ss.str();
	}

	Token match(tokenType t){
		/*
			accepts a token type
			returns the old first token
			throws an error if the token types do not match
		*/

		Token old = tokens.at(0);
		if(token_type() == t){
			advance_token();
		}else{
			throw_error();
		}
		return old;
	}

	/*datalogProgram	->	SCHEMES COLON scheme schemeList
		        			FACTS COLON factList
		        			RULES COLON ruleList
		        			QUERIES COLON query queryList
							END*/
	void datalog_program(){ 
		/*
			accepts nothing
			returns nothing
			but will initialize the class variable program
		*/

		vector<Predicate> schemes;
		match(SCHEMES);
		match(COLON);
		schemes.push_back(scheme());
		scheme_list(schemes);


		vector<Predicate> facts;
		match(FACTS);
		match(COLON);
		fact_list(facts);


		vector<Rule> rules;
		match(RULES);
		match(COLON);
		rule_list(rules);


		vector<Predicate> queries;
		match(QUERIES);
		match(COLON);
		queries.push_back(query());
		query_list(queries);
		
		match(END);


		program.initialize(schemes, facts, rules, queries);

	}


	// schemeList	->	scheme schemeList | lambda
	void scheme_list(vector<Predicate>& schemes){
		/*
			accepts a vector (by reference) of predicates to append all schemes to
			returns nothing
			but appends the next scheme to the vector
		*/

		if(token_type() == ID){
			// call scheme, which returns a Predcate object, and push it onto the vector
			schemes.push_back(scheme());
			// recursively push schemes onto the schemes vector
			scheme_list(schemes);
		}else{
			// lambda: do nothing
		}
	}

	// factList	->	fact factList | lambda
	void fact_list(vector<Predicate>& facts){
		/*
			accepts a vector (by reference) of predicates to append all facts to
			returns nothing
			but appends the next fact to the vector
		*/

		if(token_type() == ID){
			// call fact, which returns a Predicate object, and push it onto the vector
			facts.push_back(fact());
			// recursively push facts onto the fact vector
			fact_list(facts);
		}else{
			// lambda: do nothing
		}
	}

	// ruleList	->	rule ruleList | lambda
	void rule_list(vector<Rule>& rules){
		/*
			accepts a vector (by reference) of rules to append all rules to
			returns nothing
			but appends the next rule to the vector
		*/

		if(token_type() == ID){
			// call rule, which returns a Rule, and push that onto the vector.
			rules.push_back(rule());
			// recursively push rules onto the rule vector
			rule_list(rules);
		}else{
			// lambda: do nothing
		}
	}

	// queryList	->	query queryList | lambda
	void query_list(vector<Predicate>& queries){
		/*
			accepts a vector (by reference) of predicates to append all queries to
			returns nothing
			but appends the next query to the vector
		*/

		if(token_type() == ID){
			// call query, which returns a Predicate, and push that onto the vector
			queries.push_back(query());
			// recursively push queries onto the query vector
			query_list(queries);
		}else{
			// lambda: do nothing
		}
	}

	// scheme 	-> ID LEFT_PAREN ID idList RIGHT_PAREN
	Predicate scheme() {
		/*
			accepts nothing
			returns the scheme that corresponds to the next few tokens
		*/

		// match will return the token corresponding to the ID.
		// we need to get the string of that id and save it to the Predicate object
		Predicate new_scheme(match(ID).get_value());
		match(LEFT_PAREN);

		// create a new vector for the parameters
		vector<Parameter> params;

		// match returns the token of the ID
		// which is passed into the constructor for Parameter
		// which is pushed onto the parameter list
		params.push_back(Parameter(match(ID)));

		// push the rest of the ids onto the list recursively
		id_list(params);
		match(RIGHT_PAREN);

		// add the params to the Predicate object
		new_scheme.add_all(params);
		return new_scheme;
	}

	// fact  	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	Predicate fact(){
		/*
			accepts nothing
			returns the fact that corresponds to the next few tokens
		*/

		// match will return the token corresponding to the ID.
		// we need to get the string of that id and save it to the Predicate object
		Predicate new_fact(match(ID).get_value());
		match(LEFT_PAREN);

		// create a vector of parameters
		vector<Parameter> params;

		// match returns the token of the STRING
		// which is passed into the constructor for Parameter
		// which is pushed onto the parameter list
		params.push_back(Parameter(match(STRING)));

		
		string_list(params);
		match(RIGHT_PAREN);
		match(PERIOD);

		new_fact.add_all(params);
		return new_fact;
	}

	// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
	Rule rule(){
		/*
			accepts nothing
			returns the rule that corresponds to the next few tokens
		*/

		Rule new_rule(head_predicate());
		match(COLON_DASH);

		// create a vector of predicates
		vector<Predicate> preds;

		// append the first predicate to the pred list
		preds.push_back(predicate());
		predicate_list(preds);
		match(PERIOD);

		// replace all function will make the body of the rule
		new_rule.replace_all(preds);
		return new_rule;
	}

	// query	->	predicate Q_MARK
	Predicate query(){
		/*
			accepts nothing
			returns the query that corresponds to the next few tokens
		*/

		// predicate returns a Predicate object corresponding to the query in question.
		// I would love to just return this in one line, but we need to clear the Q_MARK before returning.
		Predicate new_query = predicate();
		match(Q_MARK);
		return new_query;
	}

	// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	Predicate head_predicate(){
		/*
			accepts nothing
			returns the predicate that corresponds to the next few tokens
		*/

		// match will return the token corresponding to the ID.
		// we need to get the string of that id and save it to the Predicate object
		Predicate head_pred(match(ID).get_value());
		match(LEFT_PAREN);


		vector<Parameter> params;
		// match returns the Token corresponding to the ID, 
		// which is passed into the constructor for Parameter, 
		// which is then appended to the vector 
		params.push_back(Parameter(match(ID)));
		// pass params by reference, and id_list recursively pushes all the parameters onto the vector
		id_list(params);
		match(RIGHT_PAREN);
		head_pred.add_all(params);
		return head_pred;
	}

	// predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
	Predicate predicate(){
		/*
			accepts nothing
			returns the predicate that corresponds to the next few tokens
		*/

		// match will return the token corresponding to the ID.
		// we need to get the string of that id and save it to the Predicate object
		Predicate new_pred(match(ID).get_value());
		match(LEFT_PAREN);

		// create a parameter vector, and push the parameters onto it
		// parameter_list will push the parameters onto the vector (which is passed by reference)
		vector<Parameter> params;
		params.push_back(parameter());
		parameter_list(params);
		match(RIGHT_PAREN);

		// predicate function to add all parameters, then return
		new_pred.add_all(params);
		return new_pred;
	}

	// predicateList	->	COMMA predicate predicateList | lambda
	void predicate_list(vector<Predicate>& preds){
		/*
			accepts a vector of predicates
			returns nothing
			but appends the predicates to the list recursively
		*/

		if(token_type() == COMMA){
			match(COMMA);
			// call predicate, which returns a predicate data type, and push that onto the vector
			preds.push_back(predicate());
			predicate_list(preds);
		}else{
			// lambda: do nothing
		}
	}

	// parameterList	-> 	COMMA parameter parameterList | lambda
	void parameter_list(vector<Parameter>& params){
		/*
			accepts a vector (by reference) of Parameters
			returns nothing
			but appends the next parameter to the vector
		*/

		if(token_type() == COMMA){
			match(COMMA);
			// call parameter, which returns a parameter data type, and push that onto the vector
			params.push_back(parameter());
			parameter_list(params);
		}else{
			// lambda: do nothing
		}
	}

	// stringList	-> 	COMMA STRING stringList | lambda
	void string_list(vector<Parameter>& strs){
		/*
			accepts a vector (by reference) of parameters
			returns nothing
			but appends the next string to the vector
		*/

		if(token_type() == COMMA){
			match(COMMA);
			// match a STRING, create a new parameter, and push it onto the string vector
			strs.push_back(Parameter(match(STRING)));
			string_list(strs);
		}else{
			// lambda: do nothing
		}
	}

	// idList -> COMMA ID idList | lambda
	void id_list(vector<Parameter>& ids){
		/*
			accepts a vector (by reference) of parameters
			returns nothing
			but appends the next ID to the vector
		*/

		if(token_type() == COMMA){
			match(COMMA);
			// match an ID, create a new parameter, and push it onto the id vector
			ids.push_back(Parameter(match(ID)));
			id_list(ids);
		}else{
			// lambda: do nothing
		}
	}

	// parameter	->	STRING | ID
	Parameter parameter(){
		/*
			accepts nothing
			returns the parameter corresponding the the next few tokens
		*/

		Parameter new_param(Token(STRING, "something went wrong", 0));
		if(token_type() == STRING){
			// match the token, get the old one, and initialize a parameter to return
			new_param.set_value(match(STRING));
		}else if(token_type() == ID){
			// match the token, get the old one, and initialize a parameter to return
			new_param.set_value(match(ID));
		}else{
			throw_error();
		}
		return new_param;
	}

	string toString(){
		return program.toString();
	}

	bool true_parse(){
		return parsed_true;
	}
};