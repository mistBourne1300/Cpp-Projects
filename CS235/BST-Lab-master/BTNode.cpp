#pragma once
#include "BTNode.h"

int BTNode::getData() const{
	cout << "accessed BTNode.getData() = " << this->data << endl;
	return this->data;
}

BTNode* BTNode::getLeftChild() const{
	cout << "accessed BTNode.getLeftChild()" << endl;
	return this->left;
}

BTNode* BTNode::getRightChild() const{
	cout << "accessed BTNode.getRightChild()" << endl;
	return this->right;
}

void BTNode::setChild(int d){
	cout << "accessed BTNode: " << this->data << ".setChild(" << d << ")" << endl;
	if(this->data > d){
		if(this->getLeftChild() != NULL){
			cout << "trying to make a left child where one already exists. left child: "  << this->left << endl;
			throw "trying to make a left child where one already exists";
		}
		cout << "\tsetting left child" << endl;
		this->left = new BTNode(d, this);
	}else{
		if(this->getRightChild() != NULL){
			cout << "trying to make a right child where one already exists" << endl;
			throw " trying to make a right child where one already exists";
		}
		cout << "\tsetting right child" << endl;
		this->right = new BTNode(d, this);
	}
}

BTNode* BTNode::getParent() const{
	cout << "accessed BTNode.getParent()" << endl;
	return this->parent;
}

void BTNode::setParent(BTNode* p){
	cout << "accessed BTNode.setParent()" << endl;
	this->parent = p;
	cout << "is it here?" << endl;
	p = NULL;
	cout << "still in the function" << endl;
}

void BTNode::setRightChild(BTNode* child){
	cout << "accessed BTNode.setRightChild()" << endl;
	this->right = child;
}

void BTNode::setLeftChild(BTNode* child){
	cout << "accessed BTNode.setLeftChild()" << endl;
	this->left = child;
}

void BTNode::setData(int d){
	cout << "accessed BTNode.setData()" << endl;
	this->data = d;
}

// does an inorder print of the tree. It first calls print on the left sub tree, 
// then prints itself, then calls print on the right subtree.
void BTNode::printinorder() const{
	// cout << "acccessed BTNode.print()" << endl;
	if(this->left != NULL){
		this->left->printinorder();
	}
	cout << this->data << " " << flush;
	if(this->right != NULL){
		this->right->printinorder();
	}
}

void BTNode::printpreorder() const{
	cout << this->data << " " << flush;
	if(this->left != NULL){
		this->left->printpreorder();
	}
	if(this->right != NULL){
		this->right->printpreorder();
	}
}

void BTNode::printpostorder() const{
	if(this->left != NULL){
		this->left->printpostorder();
	}
	if(this->right != NULL){
		this->right->printpostorder();
	}
	cout << this->data << " " << flush;
}