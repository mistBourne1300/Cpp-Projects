//#pragma once
#include "AVL.h"

AVLNode* AVL::find(int data) const{
	// cout << "accessed AVL.find()" << endl;
	AVLNode* curr_node = root;
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

AVLNode* AVL::findPredecessor(AVLNode* curr_node) const{
	// cout << "accessed AVL.findPredecessor()" << endl;

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

bool AVL::add(int d){
	if(root == NULL){
		root = new AVLNode(d);
		return true;
	}else{
		return addHelper(d,root);
	}
}

bool AVL::addHelper(int d, AVLNode*& localroot){
	// if(localroot != NULL) {cout << "accessed addHelper(" << d << ", " << localroot->getData() << ")" << endl;}
	
	int localdata = localroot->getData();
	if(localdata == d){
		return false;
	}
	if(localdata < d){
		AVLNode* rightChild = localroot->getRightChild();
		if(rightChild == NULL){
			localroot->setChild(d);
			return true;
		}
		
		if(addHelper(d, rightChild)){
			// print();
			this->rebalance(localroot);
			return true;
		}else{return false;}
	}
	else{
		AVLNode* leftChild = localroot->getLeftChild();
		if(leftChild == NULL){
			localroot->setChild(d);
			return true;
		}

		if(addHelper(d, leftChild)){
			// print();
			rebalance(localroot);
			return true;
		}else{return false;}
	}
}

bool AVL::remove(int d){
	return removeHelper(d, root);
}

bool AVL::removeHelper(int d, AVLNode*& localroot){
	// cout << "accessed removeHelper(" << d << ")" << endl;
	if(localroot == NULL){
		return false;
	}
	if(localroot->getData() == d){
		eraseNode(localroot);
		return true;
	}
	if(localroot->getData() < d){
		AVLNode* rchild = localroot->getRightChild();
		if(removeHelper(d, rchild)){
			rebalance(localroot);
			return true;
		}else{return false;}
	}else{
		AVLNode* lchild = localroot->getLeftChild();
		if(removeHelper(d, lchild)){
			rebalance(localroot);
			return true;
		}else{return false;}
	}
}

bool AVL::eraseNode(AVLNode*& target){
	cout << "accessed eraseNode(" << target->getData() << ")" << endl;
	AVLNode* lchild = target->getLeftChild();
	AVLNode* rchild = target->getRightChild();


	// target is a leaf node
	if(lchild == NULL && rchild == NULL){
		cout << "removing leaf" << endl;
		if(target == root){
			cout << "removing root" << endl;
			delete target;
			root = NULL;
			target = NULL;
			return false;
		}else{
			AVLNode* parent = target->getParent();
			if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				delete target;
				parent->setRightChild();
				return false;
			}else if(parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				delete target;
				parent->setLeftChild();
				return false;
			}else{
				cout << "parent: " << parent->getData();
				cout << "target: " << target->getData();
				cout << "parent cannot find target, target not children" << endl;
				throw 1;
			}
		}	
	}

	// target has only the right child
	else if(rchild != NULL && lchild == NULL){
		cout << "removing node with right child" << endl;
		target->getData();
		target->setRightChild();
		target->setLeftChild();
		target->getData();

		// if target is the root, assign child to be the root
		if(target == root){
			cout << "\tremoving root" << endl;
			target->getData();
			delete target;
			target = NULL;
			root = rchild;
			rchild->setParent();
			return false;
		}

		// target is not the root, and has a parent
		else{
			AVLNode* parent = target->getParent();
			rchild->setParent(parent);
			if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				delete target;
				parent->setRightChild(rchild);
				return false;
			}else if(parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				delete target;
				parent->setLeftChild(rchild);
				return false;
			}else{
				cout << "parent cannot find target, target not children" << endl;
				throw 1;
			}
		}
	}

	// target has only the left child 
	else if(rchild == NULL && lchild != NULL){
		cout << "removing node with left child" << endl;
		target->setLeftChild();
		target->setRightChild();

		// if the target is the root assign lchild to root
		if(target == root){
			cout << "\tremoving root" << endl;
			delete target;
			root = lchild;
			lchild->setParent();
			return false;
		}

		// target is not the root, and has a parent
		else{
			AVLNode* parent = target->getParent();
			lchild->setParent(parent);
			
			if(parent->getLeftChild() == target){
				cout << "\tremoving parent->left" << endl;
				parent->setLeftChild(lchild);
				delete target;
				return false;
			}else if(parent->getRightChild() == target){
				cout << "\tremoving parent->right" << endl;
				parent->setRightChild(lchild);
				delete target;
				return false;
			}else{
				// cout << "parent cannot find target, target has a left child" << endl;
				throw 1;
			}
		}
	}

	// target has two children, must be handled with care
	else if(rchild != NULL && lchild != NULL){
		cout << "removing parent with two children" << endl;

		AVLNode* predecessor = findPredecessor(target);
		int temp = predecessor->getData();
		target->setData(temp);
		AVLNode* predParent = predecessor->getParent();
		eraseNode(predecessor);
		rebalance(predParent);
		return true;
	}

	// something went horribly wrong
	else{
		cout << "somehow, the node to remove both has no children and has children. strange." << endl;
		throw 1;
	}
}

void AVL::rebalance(AVLNode*& localroot){
	// cout << "accessed rebalance(" << localroot->getData() << ")" << endl;
	AVLNode* rightChild = localroot->getRightChild();
	AVLNode* leftChild = localroot->getLeftChild();
	if(rightChild != NULL){
		rightChild->getData();
	}
	if(leftChild != NULL){
		leftChild->getData();
	}
	int localbalance = localroot->getBalance();
	// cout << "balance: " << localbalance << endl;
	if(localbalance == 1 || localbalance == -1 || localbalance == 0){
		// cout << "rebalance not needed: " << localbalance << endl;
		return;
	}
	// local root needs rebalancing. 
	// check to see if we have a RR, RL, LL, or LR imbalance

	// left imbalance
	if(localbalance > 0){
		int leftbalance = leftChild->getBalance();
		// a LL imbalance
		if(leftbalance >= 0){
			rightRotate(localroot);
			localroot->getData();
		}
		// a LR imbalance
		else{
			leftRotate(leftChild);
			rightRotate(localroot);
		}
	}else{
		int rightbalance = rightChild->getBalance();
		// a RR imbalance
		if(rightbalance <= 0){
			leftRotate(localroot);
			localroot->getData();
		}
		// a RL imbalance
		else{
			rightRotate(rightChild);
			leftRotate(localroot);
		}
	}
	if(root->getParent() != NULL){
		root = root->getParent();
	}

}

void AVL::rightRotate(AVLNode*& localroot){
	// cout << "accessed rightRotate("  << localroot->getData() << ")" << endl;
	AVLNode* lchild = localroot->getLeftChild();
	AVLNode* lrgchild = lchild->getRightChild();
	AVLNode* parent = localroot->getParent();
	// reassign the parent pointer of the LR grandchild to localroot
	if(lrgchild != NULL){
		lrgchild->setParent(localroot);
	}
	localroot->setLeftChild(lrgchild); // reassign the right child pointer of localroot to the LR grandchild
	lchild->setRightChild(localroot); // reassign the L child pointer of lchild to localroot
	lchild->setParent(parent); // reassign the parent pointer of lchild to parent
	// reassign reassign the appropriate child pointer of parent to lchild
	if(parent != NULL){
		if(parent->getRightChild() == localroot){
			parent->setRightChild(lchild);
		}else{
			parent->setLeftChild(lchild);
		}
	}
	localroot->setParent(lchild);
	localroot = lchild;
}

void AVL::leftRotate(AVLNode*& localroot){
	// cout << "accessed leftRotate("  << localroot->getData() << ")" << endl;
	AVLNode* rchild = localroot->getRightChild();
	AVLNode* rlgchild = rchild->getLeftChild();
	AVLNode* parent = localroot->getParent();
	// reassign the parent pointer of the RL grandchild to the localroot
	if(rlgchild != NULL){
		rlgchild->setParent(localroot);
	}
	localroot->setRightChild(rlgchild); // reassign the right child pointer of localroot the the RL grandparent
	rchild->setLeftChild(localroot); // reassign the L child pointer of rchild to localroot
	rchild->setParent(parent); // reassign the parent pointer of rchild to parent
	// reassign reassign the appropriate child pointer of parent to rchild
	if(parent != NULL){
		if(parent->getRightChild() == localroot){
			parent->setRightChild(rchild);
		}else{
			parent->setLeftChild(rchild);
		}
	}
	localroot->setParent(rchild);
	localroot = rchild;
	localroot->getData();
}

void AVL::print() const{
	if(root == NULL){
		cout << "AVL is empty" << endl;
		return;
	}
	cout << "in order:\n\t" << flush;
	this->root->printinorder();
	cout << endl << "preorder:\n\t" << flush;
	this->root->printpreorder();
	cout << endl << "postorder:\n\t" << flush;
	this->root->printpostorder();
	cout << endl;
}