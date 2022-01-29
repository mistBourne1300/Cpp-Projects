# pragma once
# include <vector>
# include <string>
using namespace std;

# include "Scanner.h"

class Parser{
private:
	vector<Token> tokens;
public:
	Parser(string filename){
		tokens = Scanner(filename).scan();
	}

	bool parse(){
		try{
			datalog_program();
		}catch(string msg){
			cout << msg << endl;
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
		ss << "error. " << err_token.enum_to_string() << " line:  " << tokens.at(0).get_line();
		throw ss.str();
	}

	void match(tokenType t){
		if(token_type() == t){
			advance_token();
		}else{
			throw_error();
		}
	}

	/*datalogProgram	->	SCHEMES COLON scheme schemeList
		        			FACTS COLON factList
		        			RULES COLON ruleList
		        			QUERIES COLON query queryList
							END*/
	void datalog_program(){
		match(SCHEMES);
		match(COLON);
		scheme();
		scheme_list();

		match(FACTS);
		match(COLON);
		fact_list();

		match(RULES);
		match(COLON);
		rule_list();

		match(QUERIES);
		match(COLON);
		query();
		query_list();
		
		match(END);
	}


	// schemeList	->	scheme schemeList | lambda
	void scheme_list(){
		if(token_type() == ID){
			scheme();
			scheme_list();
		}else{
			// lambda: do nothing
		}
	}

	// factList	->	fact factList | lambda
	void fact_list(){
		if(token_type() == ID){
			fact();
			fact_list();
		}else{
			// lambda: do nothing
		}
	}

	// ruleList	->	rule ruleList | lambda
	void rule_list(){
		if(token_type() == ID){
			rule();
			rule_list();
		}else{
			// lambda: do nothing
		}
	}

	// queryList	->	query queryList | lambda
	void query_list(){
		if(token_type() == ID){
			query();
			query_list();
		}else{
			// lambda: do nothing
		}
	}

	// scheme 	-> ID LEFT_PAREN ID idList RIGHT_PAREN
	void scheme() {
		if(token_type() == ID){
			match(ID);
			match(LEFT_PAREN);
			match(ID);
			id_list();
			match(RIGHT_PAREN);
		}else{
			throw_error();
		}
	}

	// fact  	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
	void fact(){
		match(ID);
		match(LEFT_PAREN);
		match(STRING);
		string_list();
		match(RIGHT_PAREN);
		match(PERIOD);
	}

	// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
	void rule(){
		head_predicate();
		match(COLON_DASH);
		predicate();
		predicate_list();
		match(PERIOD);
	}

	// query	->	predicate Q_MARK
	void query(){
		predicate();
		match(Q_MARK);
	}

	// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
	void head_predicate(){
		match(ID);
		match(LEFT_PAREN);
		match(ID);
		id_list();
		match(RIGHT_PAREN);
	}

	// predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
	void predicate(){
		match(ID);
		match(LEFT_PAREN);
		parameter();
		parameter_list();
		match(RIGHT_PAREN);
	}

	// predicateList	->	COMMA predicate predicateList | lambda
	void predicate_list(){
		if(token_type() == COMMA){
			match(COMMA);
			predicate();
			predicate_list();
		}else{
			// lambda: do nothing
		}
	}

	// parameterList	-> 	COMMA parameter parameterList | lambda
	void parameter_list(){
		if(token_type() == COMMA){
			match(COMMA);
			parameter();
			parameter_list();
		}else{
			// lambda: do nothing
		}
	}

	// stringList	-> 	COMMA STRING stringList | lambda
	void string_list(){
		if(token_type() == COMMA){
			match(COMMA);
			match(STRING);
			string_list();
		}else{
			// lambda: do nothing
		}
	}

	// idList -> COMMA ID idList | lambda
	void id_list(){
		if(token_type() == COMMA){
			match(COMMA);
			match(ID);
			id_list();
		}else{
			// lambda: do nothing
		}
	}

	// parameter	->	STRING | ID
	void parameter(){
		if(token_type() == STRING){
			match(STRING);
		}else if(token_type() == ID){
			match(ID);
		}else{
			throw_error();
		}
	}

};