#pragma once
#include <ctime>
#include <random>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
#include "PathfinderInterface.h"

class Pathfinder : public PathfinderInterface {
private:
	char maze[5][5][5];
	char tempmaze[5][5][5];
	vector<string> solution;
	bool isPath(int i, int j, int k);
	void updateFromTemp();
public:
	Pathfinder(){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				for(int k = 0; k < 5; k++){
					this->maze[i][j][k] = 1;
				}
			}
		}
	}
	~Pathfinder(){
		cout << "exit" << endl;
	}
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};