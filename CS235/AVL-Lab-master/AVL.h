#pragma once
#include "AVLInterface.h"
#include "AVLNode.cpp"

class AVL : public AVLInterface{
private:
	AVLNode* root;
	AVLNode* find(int data) const; //returns NULL if not found
	AVLNode* findPredecessor(AVLNode* curr_node) const; //returns NULL if not found
	bool addHelper(int d, AVLNode*& localroot);
	bool removeHelper(int d, AVLNode*& localroot);
	bool eraseNode(AVLNode*& target);
	void rebalance(AVLNode*& localroot);
	void rightRotate(AVLNode*& locaroot);
	void leftRotate(AVLNode*& locaroot);
public:
	AVL(){
		// cout << "accesssed AVL()" << endl;
		root = NULL;
	}

	~AVL(){
		cout << "accessed ~AVL()" << endl;
		delete root;
	}

	AVLNode* getRootNode() const {return root;}
	bool add(int d);
	bool remove(int d);
	void clear() {delete root; root = NULL;}
	void print() const;
};