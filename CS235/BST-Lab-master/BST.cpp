#pragma once
#include "BST.h"

BTNode* BST::find(int data) const{
	cout << "accessed BST.find()" << endl;
	BTNode* curr_node = root;
	while(curr_node != NULL){
		if(curr_node->getData() == data){
			return curr_node;
		}
		// if the data is larger than the current node's data, we need to go right
		if(curr_node->getData() < data){
			curr_node = curr_node->getRightChild();
		}
		// if the data is smaller, we need to go left
		else{
			curr_node = curr_node->getLeftChild();
		}
	}
	return NULL;
}

BTNode* BST::findPredecessor(int data) const{
	cout << "accessed BST.findPredecessor()" << endl;
	BTNode* curr_node = find(data);
	if(curr_node == NULL){
		cout << "could not find predecessor of data" << endl;;
		throw 1;
	}
	if(curr_node->getLeftChild() == NULL){
		cout << "current node has no left child: cannot find immedaite predecessor" << endl;
		throw 1;
	}
	curr_node = curr_node->getLeftChild();
	while(curr_node->getRightChild() != NULL){
		curr_node = curr_node->getRightChild();
	}
	return curr_node;
}

BTNode* BST::getRootNode() const{
	cout << "accessed BST.getRootNode()" << endl;
	return this->root;
}

bool BST::add(int data){
	cout << "accessed BST.add(" << data << ")" << endl;
	BTNode* curr_node = this->root;
	BTNode* prev = NULL;
	while(curr_node != NULL){
		if(curr_node->getData() == data){
			return false;
		}
		prev = curr_node;
		if(curr_node->getData() < data){
			curr_node = curr_node->getRightChild();
		}else{
			curr_node = curr_node->getLeftChild();
		}
	}
	if(prev == NULL){
		root = new BTNode(data);
		return true;
	}
	prev->setChild(data);
	return true;
}

void BST::clear(){
	cout << "accessed BST.clear()" << endl;
	delete this->root;
	this->root = NULL;
}

bool BST::remove(int data){
	cout << "accessed BST.remove(" << data<< ")" << endl;
	BTNode* target = this->find(data);
	// if the data is not in the tree, return false
	if(target == NULL){
		return false;
	}
	// target has no children. just remove it
	if(target->getLeftChild() == NULL && target->getRightChild() == NULL){
		cout << "removing leaf" << endl;
		if(target == this->root){
			cout << "\nremoving root" << endl;;
			delete target;
			this->root = NULL;
			target = NULL;
			return true;
		}else{
			BTNode* parent = target->getParent();
			if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				delete target;
				parent->setRightChild();
				return true;
			}else if (parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				delete target;
				parent->setLeftChild();
				return true;
			}else{
				cout << "parent cannot find target, target not children" << endl;
				throw 1;
			}
		}
	}
	// target has only the right child, parent needs to adopt it
	else if(target->getRightChild() != NULL && target->getLeftChild() == NULL){
		cout << "removing node with right child" << endl;
		BTNode* child = target->getRightChild();
		target->setRightChild();
		target->setLeftChild();

		// if the target is the root, assign child to be root
		if(target == this->root){
			cout << "\tremoving root" << endl;
			this->root = child;
			child->setParent();
			target->setRightChild();
			target->setLeftChild();
			delete target;
			return true;
		}

		// target is not the root, and has a parent
		else{
			BTNode* parent = target->getParent();
			child->setParent(parent);
			cout << "returned successfully" << endl;
			if(parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				parent->setLeftChild(child);
				delete target;
				return true;
			}else if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				parent->setRightChild(child);
				delete target;
				return true;
			}else{
				cout << "parent cannot find target, target has a left child" << endl;
				throw 1;
			}
		}
	}
	// target has only the left child, parent must adopt it
	else if(target->getRightChild() == NULL && target->getLeftChild() != NULL){
		cout << "removing node with left child" << endl;
		BTNode* child = target->getLeftChild();
		target->setLeftChild();
		target->setRightChild();

		// if the target is the root, assign cild to be root
		if(target == this->root){
			cout << "\tremoving root" << endl;
			this->root = child;
			child->setParent();
			delete target;
			return true;
		}

		// target is not the root, and has a parent
		else{
			BTNode* parent = target->getParent();
			child->setParent(parent);
			cout << "returned successfully" << parent << endl;
			if(parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				parent->setLeftChild(child);
				delete target;
				return true;
			}else if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				parent->setRightChild(child);
				delete target;
				return true;
			}else{
				cout << "parent cannot find target, target has a left child" << endl;
				throw 1;
			}
		}
	}
	// target has two children, must be handled with caution
	else if(target->getRightChild() != NULL && target->getLeftChild() != NULL){
		cout << "removing parent with two children" << endl;
		
		BTNode* predecessor = this->findPredecessor(data);

		int temp = predecessor->getData();
		this->remove(temp);
		target->setData(temp);
		return true;
	}
	// something went horribly wrong
	else{
		cout << "somehow, the node to remove both has no children and has children. strange." << endl;
		throw 1;
	}
}

void BST::print() const{
	cout << "in order:\n\t" << flush;
	this->root->printinorder();
	cout << endl << "preorder:\n\t" << flush;
	this->root->printpreorder();
	cout << endl << "postorder:\n\t" << flush;
	this->root->printpostorder();
	cout << endl;
}