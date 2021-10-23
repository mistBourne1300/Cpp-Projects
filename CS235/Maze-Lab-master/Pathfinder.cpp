#pragma once

#include "Pathfinder.h"

string Pathfinder::toString() const{
	bool mazeImplemented = 0;
	ostringstream outstream;
	if(maze[0][0][0] == '1'){
		mazeImplemented = 1;
	}
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5;j++){
			for(int k = 0; k < 5; k++){
				if(mazeImplemented){
					outstream << maze[k][j][i];
				}else{
					outstream << 1;
				}
				if(k<4){
					outstream << " ";
				}
			}
			if(j<4){
				outstream << "\n";
			}
		}
		if(i<4){
			outstream << "\n\n";
		}
	}
	outstream << "\n";
	return outstream.str();
}

bool Pathfinder::importMaze(string file_name){
	// needs to check: 
	//		whether each number is a 0 or a 1
	//		whether the whitespace is in the correct position
	//		whether there are exactly 125 0's and 1's
	
	string mazeline_string;
	ifstream infile;
	infile.open(file_name);
	bool success = true;
	if(!infile.is_open()){
		cout << "failed to open file" << file_name << endl;
		return false;
	}

	for(int i = 0; i < 5; i++){
		// loop for every 5x5 block
		for(int j = 0; j < 5; j++){
			// loop for every line
			getline(infile, mazeline_string);
			istringstream mazeline(mazeline_string);
			string zeroth, first, second, third, fourth;
			mazeline >> zeroth >> first >> second >> third >> fourth;
			if(zeroth != "0" && zeroth != "1"){
				cout << "maze[" << i << "][" << j << "][0] not a 0 or a 1" << endl;
				return false;
			}
			if(first != "0" && first != "1"){
				cout << "maze[" << i << "][" << j << "][1] not a 0 or a 1" << endl;
				return false;
			}
			if(second != "0" && second != "1"){
				cout << "maze[" << i << "][" << j << "][2] not a 0 or a 1" << endl;
				return false;
			}
			if(third != "0" && third != "1"){
				cout << "maze[" << i << "][" << j << "][3] not a 0 or a 1" << endl;
				return false;
			}
			if(fourth != "0" && fourth != "1"){
				cout << "maze[" << i << "][" << j << "][4] not a 0 or a 1" << endl;
				return false;
			}
			tempmaze[0][j][i] = zeroth[0];
			tempmaze[1][j][i] = first[0];
			tempmaze[2][j][i] = second[0];
			tempmaze[3][j][i] = third[0];
			tempmaze[4][j][i] = fourth[0];

		}
		getline(infile, mazeline_string);
		if(!mazeline_string.empty() && i < 4){
			cout << "block " << i << " newline missing" << endl;
			return false;
		}
	}
	if(!infile.eof()){
		cout << "did not reach end of file" << endl;
		return false;
	}

	
	if(tempmaze[0][0][0] != '1'){
		cout << "maze[0][0][0] not a 1" << endl;
		return false;
	}
	if(tempmaze[4][4][4]!= '1'){
		cout << "maze [4][4][4] not a 1: " << endl;
		return false;
	}
	cout << toString() << endl;
	updateFromTemp();
	return true;
}

void Pathfinder::createRandomMaze(){
	srand(time(NULL));
	vector<char> values;
	values.push_back('0');
	values.push_back('1');
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				int value = rand() % 2;
				maze[k][j][i] = values[value];
			}
		}
	}
	maze[0][0][0] = '1';
	maze[4][4][4] = '1';
}

vector<string> Pathfinder::solveMaze(){
	while(!solution.empty()){
		solution.erase(solution.begin());
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				tempmaze[k][j][i] = maze[k][j][i];
			}
		}
	}
	isPath(0,0,0);
	reverse(solution.begin(), solution.end());
	cout << "\n\n\n\n" << endl;
	for(int i = 0; i < solution.size(); i++){
		cout << "node " << i << ": ";
		cout << solution.at(i) << endl;

	}
	cout << "\n\n\n\n\n" << endl;
	return solution;
}

bool Pathfinder::isPath(int i, int j, int k){
	// base cases
	if(i > 4 || j > 4 || k > 4){
		return false;
	}
	
	if(i < 0 || j < 0 || k < 0){
		return false;
	}
	
	if(i == 4 && j == 4 && k == 4){
		solution.push_back("(4, 4, 4)");
		return true;
	}
	
	if(tempmaze[k][j][i] == '0'){
		return false;
	}
	tempmaze[k][j][i] = '0';
	if(isPath(i+1,j,k)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;
	}else if(isPath(i,j+1,k)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;

	}else if(isPath(i,j,k+1)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;

	}else if(isPath(i-1,j,k)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;

	}else if(isPath(i,j-1,k)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;

	}else if(isPath(i,j,k-1)){
		ostringstream path;
		path << "(" << k;
		path << ", " << j;
		path << ", " << i;
		path << ")";
		solution.push_back(path.str());
		return true;

	}
	return false;
}

void Pathfinder::updateFromTemp(){
	for(int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				maze[k][j][i] = tempmaze[k][j][i];
			}
		}
	}
}