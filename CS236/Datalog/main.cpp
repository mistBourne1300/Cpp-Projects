# include <iostream>
# include <utility>
using namespace std;

# include "Token.h"
# include "Scanner.h"
# include "Parser.h"
# include "Scheme.h"
# include "Tuple.h"
# include "Relation.h"
# include "Database.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "database requires at least one argument <filename>" << endl;
		return 1;
	}

	Database death_star(argv[1]);
	if(!death_star.get_success()){
		cout << "failed to parse file. exiting." << endl;
		return 1;
	}
	cout << death_star.evaluate();

}


// What about that shadowed area? That is old code. Never venture there, my son. 
// int main(){
// 	vector<string> names = {"a","b","c","d","e"};
// 	Scheme scheme(names);
// 	Relation relation("student", scheme);
// 	vector<vector<string> > values = {
// 		{"2","2","4","4","4"},
// 		{"2","2","4","2","2"}
// 	};

// 	for(vector<string> value : values){
// 		Tuple tuple(value);
// 		relation.add_tuple(tuple);
// 	}

// 	cout << "relation:" << endl;
// 	cout << relation.toString() << endl;

// 	vector<int> indices = {0,1,3,4};
// 	relation = relation.select_similar(indices);
// 	cout << "selected similar" << endl;
// 	cout << relation.toString() << endl;;

// 	vector<string> re = {"z", "z", "x", "z", "z"};
// 	relation = relation.rename(names, re);
// 	cout << "renamed:" << endl;
// 	cout << relation.toString() << endl;

// 	relation = relation.projector(re);
// 	cout << "projected:" << endl;
// 	cout << relation.toString() << endl;

// }




// old code for lab 2
// int main(int argc, char *argv[]) {
//   if(argc < 2){
// 		cout << "datalog requires at least one argument <filename>" << endl;
// 		return 1;
// 	}

// 	// Scanner s = Scanner();
// 	// if(!s.readFile(argv[1])){
// 	// 	cout << "failed to read file: " << argv[1] << endl;
// 	// 	throw "file read error";
// 	// }
// 	// vector<Token> tokens = s.Scan();
// 	// for(unsigned int i = 0; i < tokens.size(); i++){
// 	// 	cout << tokens.at(i).toString() << endl;
// 	// }
// 	// cout << "Total Tokens = " << tokens.size() << endl;

//   Parser p = Parser(argv[1]);
//   if(p.true_parse()){
//     cout << "Success!" << endl;
// 	cout << p.toString();
//   }else{
//     // cout << "uh oh" << endl;
//   }
// }

// old code for lab 1
// int main(){
// 	vector<Token> tokens = {
//     Token(ID,"Ned",2),
//     //Token(LEFT_PAREN,"(",2),
//     Token(ID,"Ted",2),
//     Token(COMMA,",",2),
//     Token(ID,"Zed",2),
//     Token(RIGHT_PAREN,")",2),
//   };
	
// 	Parser p = Parser(tokens);
// 	p.scheme();
// }