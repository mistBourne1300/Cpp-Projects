#pragma once
#include "NodeInterface.h"
#include <exception>
using namespace std;



class BTNode : public NodeInterface{
private: 
	int data;
	BTNode* left;
	BTNode* right;
	BTNode* parent;
public:
	BTNode(int d=0, BTNode* p = NULL){
		cout << "accessed BTNode()" << endl;
		left = NULL;
		right = NULL;
		parent = p;
		this->data = d;
	}
	~BTNode(){
		cout << "acccessed ~BTNode()" << endl;
		delete left;
		delete right;
		// cannot delete the parent, as the parent is what will be calling this destructor in the first place
		// some sort of error will occur, of that I'm sure
	}

	int getData() const;
	BTNode* getLeftChild() const;
	BTNode* getRightChild() const;
	void setChild(int data);
	void setRightChild(BTNode* child = NULL);
	void setLeftChild(BTNode* child = NULL);
	BTNode* getParent() const;
	void setParent(BTNode* p = NULL);
	void setData(int d);
	void printinorder() const;
	void printpreorder() const;
	void printpostorder() const;
};