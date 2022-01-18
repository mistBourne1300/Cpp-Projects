#include <iostream>
#include <utility>
using namespace std;

#include "Token.h"
#include "Scanner.h"


int main(int argc, char *argv[]) {
	if(argc < 2){
		cout << "tokens requires at least one argument <filename>" << endl;
		return 1;
	}

	Scanner s = Scanner();
	if(!s.readFile(argv[1])){
		cout << "failed to read file: " << argv[1] << endl;
		throw "file read error";
	}
	pair<vector<Token>, int> tokens = s.Scan();
	for(int i = 0; i < tokens.second; i++){
		cout << tokens.first.at(i).toString() << endl;
	}
	cout << "Total Tokens = " << tokens.second << flush;
}