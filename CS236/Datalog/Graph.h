# pragma once
# include <map> 
# include <sstream>
using namespace std;


# include "Node.h"


class Graph {

private:

	map<int,Node> nodes;

public:

	Graph(int size) {
		for (int nodeID = 0; nodeID < size; nodeID++) nodes[nodeID] = Node();
	}

	void add_edge(int fromNodeID, int toNodeID) {
		nodes[fromNodeID].addEdge(toNodeID);
	}
	
	string toString(){
		stringstream out;
		for(auto& pair : nodes){
			int nodeID = pair.first;
			const Node& node = pair.second;
			out << "R" << nodeID << ":" << node.toString() << endl;
		}
		return out.str();
	}
};
