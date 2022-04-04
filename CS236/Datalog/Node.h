# pragma once
# include <set>
# include <string>
# include <sstream>
using namespace std;

class Node {

private:
	set<int> adjacentNodeIDs;
public:
	void addEdge(int adjacentNodeID) {
		adjacentNodeIDs.insert(adjacentNodeID);
	}
	set<int> get_adjacent() const{
		return adjacentNodeIDs;
	}
	string toString() const{
		stringstream out;
		int counter = 1;
		int size = adjacentNodeIDs.size();
		for(int id : adjacentNodeIDs){
			out << "R" << id;
			if(counter != size){
				out << ",";
			}
		counter++;
		}
		string temp = out.str();
		return temp;
	}
};