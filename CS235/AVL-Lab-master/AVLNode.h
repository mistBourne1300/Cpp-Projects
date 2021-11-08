#pragma once
#include <exception>
#include <iostream>
using namespace std;
#include "NodeInterface.h"

class AVLNode: public NodeInterface{
private:
	int data;
	AVLNode* left;
	AVLNode* right;
	AVLNode* parent;

public:
	AVLNode(int d=0, AVLNode* p = NULL){
		// cout << "accessed AVLNode()" << endl;
		left = NULL;
		right = NULL;
		parent = p;
		data = d;
	}
	~AVLNode(){
		cout << "accessed ~AVLNode(" << data << ")" << endl;
		delete left;
		delete right;
	}

	int getData() const;
	AVLNode* getLeftChild() const;
	AVLNode* getRightChild() const;
	void setChild(int data);
	void setRightChild(AVLNode* child = NULL);
	void setLeftChild(AVLNode* child = NULL);
	AVLNode* getParent() const;
	void setParent(AVLNode* p = NULL);
	void setData(int d);
	void printinorder() const;
	void printpreorder() const;
	void printpostorder() const;
	int getHeight();
	int getBalance();
};