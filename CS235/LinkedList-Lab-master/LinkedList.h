#pragma once
#include "LinkedListInterface.h"

#include <iostream>
#include <sstream>
#include <system_error>
using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>{

	struct Node{
		T item;
		Node* next;
	};
	Node* head;
	size_t num_items;
	int find(T data);

public: 
	LinkedList(void){
		cout << "accessed constructor" << endl;
		head = NULL;
		num_items = 0;
	}
	~LinkedList(void){
		cout << "accessed destructor" << endl;
		clear();
	}
	void insertHead(T value);
	void insertTail(T value);
	void insertAfter(T value, T insertionNode);
	void remove(T value);
	void clear();
	T at(int index);
	int size();
	string toString();
};