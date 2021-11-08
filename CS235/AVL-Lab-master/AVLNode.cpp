#pragma once
#include "AVLNode.h"

int AVLNode::getData() const{
	// cout << "accessed AVLNode.getData() = " << this->data << endl;
	return this->data;
}

AVLNode* AVLNode::getLeftChild() const{
	// cout << "accessed AVLNode.getLeftChild()" << endl;
	return this->left;
}

AVLNode* AVLNode::getRightChild() const{
	// cout << "accessed AVLNode.getRightChild()" << endl;
	return this->right;
}

void AVLNode::setChild(int d){
	// cout << "accessed AVLNode: " << this->data << ".setChild(" << d << ")" << endl;
	if(this->data > d){
		if(this->getLeftChild() != NULL){
			cout << "trying to make a left child where one already exists. left child: "  << this->left << endl;
			throw "trying to make a left child where one already exists";
		}
		// cout << "\tsetting left child" << endl;
		this->left = new AVLNode(d, this);
	}else{
		if(this->getRightChild() != NULL){
			cout << "trying to make a right child where one already exists" << endl;
			throw " trying to make a right child where one already exists";
		}
		// cout << "\tsetting right child" << endl;
		this->right = new AVLNode(d, this);
	}
}

AVLNode* AVLNode::getParent() const{
	// cout << "accessed AVLNode.getParent()" << endl;
	return this->parent;
}

void AVLNode::setParent(AVLNode* p){
	// cout << "accessed AVLNode.setParent()" << endl;
	this->parent = p;
	p = NULL;
}

void AVLNode::setRightChild(AVLNode* child){
	// cout << "accessed AVLNode.setRightChild()" << endl;
	this->right = child;
}

void AVLNode::setLeftChild(AVLNode* child){
	// cout << "accessed AVLNode.setLeftChild()" << endl;
	this->left = child;
}

void AVLNode::setData(int d){
	// cout << "accessed AVLNode.setData()" << endl;
	this->data = d;
}

// does an inorder print of the tree. It first calls print on the left sub tree, 
// then prints itself, then calls print on the right suAVLree.
void AVLNode::printinorder() const{
	// cout << "acccessed AVLNode.print()" << endl;
	if(this->left != NULL){
		this->left->printinorder();
	}
	cout << this->data << " " << flush;
	if(this->right != NULL){
		this->right->printinorder();
	}
}

void AVLNode::printpreorder() const{
	cout << this->data << " " << flush;
	if(this->left != NULL){
		this->left->printpreorder();
	}
	if(this->right != NULL){
		this->right->printpreorder();
	}
}

void AVLNode::printpostorder() const{
	if(this->left != NULL){
		this->left->printpostorder();
	}
	if(this->right != NULL){
		this->right->printpostorder();
	}
	cout << this->data << " " << flush;
}

int AVLNode::getHeight(){
	if(right == NULL && left == NULL){
		return 0;
	}else if(right == NULL){
		return left->getHeight() + 1;
	}else if(left == NULL){
		return right->getHeight() + 1;
	}
	int heightRight = right->getHeight();
	int heightLeft = left->getHeight();
	if(heightRight >= heightLeft){
		return heightRight + 1;
	}else{
		return heightLeft + 1;
	}
}

int AVLNode::getBalance(){
	// cout << "accessed AVLNode.getBalance()" << endl;
	AVLNode* right = this->getRightChild();
	AVLNode* left = this->getLeftChild();
	if(left == NULL && right == NULL){
		return 0;
	}
	if(left == NULL){
		return 0 - (right->getHeight() + 1);
	}
	if(right == NULL){
		return left->getHeight() + 1;
	}
	return left->getHeight() - right->getHeight();
}