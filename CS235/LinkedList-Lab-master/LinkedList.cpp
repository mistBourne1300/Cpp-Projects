#pragma once

#include "LinkedList.h"

template<typename T>
void LinkedList<T>::insertHead(T value){
	cout << "accessed insertHead(" << value << ")" << endl;
	// cannot allow duplicate data. need to make sure the new data isn't a duplicate
	// Which, BTW, defeats the entire reason to use a linked list
	// if I have to iterate through the entire list to check if the new data
	// is a duplicate before inserting at the head, then insertion at the head is
	// O(n), not O(1). The entire point of linked lists is to have constant-time head and/or
	// tail insertion/removal. But that's the lab spec, so here's your duplicate-checking code:
	
	// cout << "find(value): " << find(value) << endl;
	if(find(value) >= 0){
		return;
	}

	Node* newHead = new Node();
	newHead->item = value;
	// if head DNE, we can't get head.next
	if(head == NULL){
		head = newHead;
		num_items++;
		return;
	}
	// passed if statement, head is not NULL
	newHead->next = head;
	head = newHead;
	num_items++;
}

template<typename T>
void LinkedList<T>::insertTail(T value){
	cout << "accessed insertTail(" << value << ")" << endl;
	// cout << "find(value): " << find(value) << endl;
	if (find(value) >= 0){
		return;
	}
	if(head == NULL){ // list is empty, just assign a head
		insertHead(value);
		return;
	}
	Node* curr_node;
	for(curr_node = head; curr_node->next != NULL; curr_node = curr_node->next); // get a pointer to the tail
	Node* newtail = new Node();
	newtail->item = value;
	curr_node->next = newtail;
	num_items++;
}

template<typename T>
void LinkedList<T>::insertAfter(T value, T insertionNode){
	cout << "accessed insertAfter(" << value << "," << insertionNode << ")" << endl;
	// cout << "find(value): " << find(value) << endl;
	if (find(value) >= 0){
		return;
	}
	// cout << "value " << value << " not in list" << endl;
	Node* curr_node;
	for(curr_node = head; curr_node->item != insertionNode; curr_node = curr_node->next){// get pointer to the node containing insertionNode
		if(curr_node->next == NULL){
			return;
		}
	}
	Node* newnode = new Node();
	newnode->item = value;
	newnode->next = curr_node->next;
	curr_node->next = newnode;
	num_items++;
}

template<typename T>
void LinkedList<T>::remove(T value){
	cout << "accessed remove(" << value << ")" << endl;
	if(head == NULL){
		return;
	}
	if(head->item == value){ // the value is at the front of the list, need to reassign head
		Node* node_to_delete = head;
		head = head->next;
		delete node_to_delete;
		node_to_delete = NULL;
		num_items--;
		return;
	}
	for(Node* curr_node = head; curr_node->next != NULL; curr_node = curr_node->next){
		if(curr_node->next->item == value){ // we need the pointer to the previos node, otherwise we can't get back to it
			Node* node_to_delete = curr_node->next;
			curr_node->next = curr_node->next->next;
			delete node_to_delete;
			node_to_delete = NULL;
			num_items--;
			return;
		}
	}
}

template<typename T>
void LinkedList<T>::clear(){
	cout << "accessed clear()" << endl;
	while(num_items > 0){
		remove(head->item);
	}
	return;
}

template<typename T>
T LinkedList<T>::at(int index){
	cout << "accessed at(" << index << ")" << endl;
	if (index >= num_items){
		throw out_of_range("linked list index out of range");
	}
	Node* curr_node = head;
	for(int i = 0; i < index; i++){
		curr_node = curr_node->next;
	}
	return curr_node->item;
}

template<typename T>
int LinkedList<T>::size(){
	cout << "accessed size()" << endl;
	return num_items;
}

template<typename T>
string LinkedList<T>::toString(){
	cout << "accessed toString" << endl;
	ostringstream return_string;
	Node* curr_node = head;
	while (curr_node != NULL){
		// if the current node is the last in the list, do not add a trailing space
		if(curr_node->next == NULL){
			return_string << curr_node->item;
		}else{
			return_string << curr_node->item << " ";
		}
		curr_node = curr_node->next;
	}
	return return_string.str();
}

template<typename T>
int LinkedList<T>::find(T data){
	cout << "accessed find(" << data << ")" << endl;
	Node* curr_node = head;
	for(int i = 0; i < num_items; i++){
		// cout << "i:" << i << endl;
		// cout << "\tcurr_node->item: " << curr_node->item << endl;
		if(curr_node->item == data){
			return i; // data found in list, return index
		}
		// cout << "\there?" << endl;
		curr_node = curr_node->next;
		// cout << "\t or here?" << endl;
	}
	return -1; // data not found, return -1
}