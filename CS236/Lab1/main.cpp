# include <iostream>
# include <utility>
using namespace std;

# include "Token.h"
# include "Scanner.h"
# include "Parser.h"

// old code for lab 1
int main(int argc, char *argv[]) {
  if(argc < 2){
		cout << "tokens requires at least one argument <filename>" << endl;
		return 1;
	}

	// Scanner s = Scanner();
	// if(!s.readFile(argv[1])){
	// 	cout << "failed to read file: " << argv[1] << endl;
	// 	throw "file read error";
	// }
	// vector<Token> tokens = s.Scan();
	// for(unsigned int i = 0; i < tokens.size(); i++){
	// 	cout << tokens.at(i).toString() << endl;
	// }
	// cout << "Total Tokens = " << tokens.size() << endl;

  Parser p = Parser(argv[1]);
  if(p.parse()){
    cout << "success!" << endl;
  }else{
    cout << "uh oh" << endl;
  }
}

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