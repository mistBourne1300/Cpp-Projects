#pragma once
#include "BTNode.cpp"
#include "BSTInterface.h"

class BST : public BSTInterface{
private:
	BTNode* root;
	BTNode* find(int data) const; //returns NULL if not found
	BTNode* findPredecessor(int data) const; //returns NULL if not found
	
public:
	BST(){
		cout << "accessed BST()" << endl;
		root = NULL;
	}
	~BST(){
		cout << "accessed ~BST()" << endl;
		delete root;
		//before root is deleted, it calls delete on its children, as per the BTNode deconstructor
		//each child then deletes its children, and so forth, clearing the tree without memeory leaks
	}

	BTNode* getRootNode() const;
	bool add(int data);
	bool remove(int data);
	void clear();
	void print() const;
};