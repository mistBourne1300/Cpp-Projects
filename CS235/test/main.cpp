#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	if(argc < 2){
		cout << "you must pass in at least one command line argument" << endl;
	return 1;
	}
	for(int i = 0; i < argc; i++){
		cout << "Argument #" << i << ": " << argv[i] << endl;
	}
	return 0;
}
