# bstlab
In this learning activity, we will set up the environment for the bst lab.  You should be able to do this on your own, but this tutorial should help you if you get lost along the way.  Try to do as much as you can on your own.  I would like to help you get set up to talk to the test driver so you can implement the functionality and learn how to use recursion to access tree containers.

First download the lab code, a copy can be found in this repository.  You should have main.cpp BSTInterface.h BST.cpp BTNode.h and the test files.  

You will need to inherit from BSTInterface.h to create BST.h.  And you will need to create an implementation file for this class (BST.cpp).

You will also need to inherit from NodeInterface.h to create Node.h  And you will need to create an implementation file for this class (Node.cpp).  Create stubs for all of the functions.


Create a Makefile to compile your code.  This Makefile will also create the program from the book so you can understand this code.
```
TARGETS = Test_Binary_Search_Tree_Numbers bst
CC = g++
CCFLAGS = -std=c++11 -g
bst: main.cpp BSTInterface.h NodeInterface.h BST.h BST.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o bst main.cpp BST.cpp Node.cpp
Test_Binary_Search_Tree_Numbers: Test_Binary_Search_Tree_Numbers.cpp Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CC) $(CCFLAGS) -o Test_Binary_Search_Tree_Numbers Test_Binary_Search_Tree_Numbers.cpp
```

Now create enough of an implementation to get the code to compile.  We know that we will need a root, so add to Bst.h
```c++
protected:
	Node *root;
```
And lets stub in enough of the code to let us see that we can access the Node structure in "BST.cpp".
```c++
	bool BST::add(int data)
	{
	    cout << "add"<<endl;
	    Node *ptr = new Node(data);
	    ptr->leftChild = NULL; // To test that the friend relationship works
	    NodeInterface *rval = ptr->getLeftChild();
	    long value = (long)rval;
	    cout << "Added "<<value<<endl;
	    root = ptr;
	}
```
Now you can implement the real code.  You can get good ideas from the code in Binary_Search_Tree.h, but dont use any code that you dont understand.
You can find the book code here http://bcs.wiley.com/he-bcs/Books?action=resource&bcsId=2949&itemId=0471467553&resourceId=7105

From Koffman, Elliot B. (2011-12-01). Objects, Abstraction, Data Structures and Design: Using C++. Wiley Higher Ed. Kindle Edition.
