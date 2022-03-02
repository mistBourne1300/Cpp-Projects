# include <iostream>
# include <utility>
using namespace std;

# include "Token.h"
# include "Scanner.h"
# include "Parser.h"
# include "Scheme.h"
# include "Tuple.h"
# include "Relation.h"

int main(){
	vector<string> names = {"ID","Name","Major"};
	Scheme scheme(names);
	Relation relation("student", scheme);
	vector<vector<string> > values = {
		{"'42'", "'Ann'", "'CS'"},
		{"'32'", "'Bob'", "'CS'"},
		{"'64'", "'Ned'", "'EE'"},
		{"'16'", "'Jim'", "'EE'"}
	};

	for(vector<string> value : values){
		Tuple tuple(value);
		cout << tuple.toString(scheme) << endl;
		relation.add_tuple(tuple);
	}

	cout << "relation:" << endl;
	cout << relation.toString();

	Relation result = relation.select(2,"'CS'");
	cout << "select Major='CS' result:" << endl;
	cout << result.toString();
}




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