# pragma once
# include <map> 
# include <sstream>
# include <stack>
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

	Graph reverse(){
		Graph reversed(nodes.size());
		for(unsigned int reversed_to = 0; reversed_to < nodes.size(); reversed_to++){
			Node toNode = nodes[reversed_to];
			for(unsigned int reversed_from: toNode.get_adjacent()){
				reversed.add_edge(reversed_from,reversed_to);
			}
		}
		return reversed;
	}

	void DFS_postorder(stack<int>& postorder, const Node& curr_head, set<int>& searched, int curr_ID){
		// if the current node has already been searched, simply return.
		// otherwise, run DFS on the current node
		if(!searched.insert(curr_ID).second){
			return;
		}

		// for each neighboring node, run DFS
		// if the neighbor set is empty, this will never run
		for(unsigned int next_ID: curr_head.get_adjacent()){
			DFS_postorder(postorder, nodes[next_ID], searched, next_ID);
		}

		// push the current node to the postorder
		postorder.push(curr_ID);
	}

	void DFS_SCC(set<int>& SCC, const Node& curr_head, set<int>& searched, int curr_ID){
		// if the searched set already has the current node, just return and do nothing
		if(!searched.insert(curr_ID).second){
			return;
		}

		// insert the current node to the SCC set
		SCC.insert(curr_ID);

		// continue the DFS search
		for(unsigned int next_ID: curr_head.get_adjacent()){
			DFS_SCC(SCC, nodes[next_ID], searched, next_ID);
		}
	}

	map<int,Node> get_Node_map() const{
		return nodes;
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
