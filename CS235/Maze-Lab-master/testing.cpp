#include <iostream>
using namespace std;
#include "Pathfinder.cpp"

int main(){
	Pathfinder pthfnder;
	pthfnder.createRandomMaze();
	cout << pthfnder.toString() << endl;
	vector<string> path = pthfnder.solveMaze();
	for(int i = 0; i < path.size(); i++){
		cout << "here";
		cout << path.at(i) << endl;
	}
	if(!(pthfnder.importMaze("Mazes/Solvable1.txt"))){
		cout << "failed to import" << endl;
		return 1;
	}
	path = pthfnder.solveMaze();
	for(int i = 0; i < path.size(); i++){
		cout << "node " << i << ": ";
		cout << path.at(i) << endl;

	}
}