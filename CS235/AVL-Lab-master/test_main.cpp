#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "AVL.cpp"

int main(){
	AVL aspen;
	for(int i = 0; i < 1000; i++){
		aspen.add(i);
		// aspen.print();
	}
	int remove = 0;
	aspen.print();
	do{
		cout << "enter the number you would like to remove (-1 to quit): ";
		cin >> remove;
		cout << endl;
		aspen.remove(remove);
		aspen.print();
	}while(remove >= 0);
}