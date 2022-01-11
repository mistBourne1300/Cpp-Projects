#include <iostream>
#include <string>
#include <sstream>
using namespace std;



int main(int argc, char* argv[]){
	if(argc < 2){
		cout << "you must pass in at least one command line argument" << endl;
	return 1;
	}
	for(int i = 0; i < argc; i++){
		cout << "Argument #" << i << ": " << argv[i] << endl;
	}

	struct Node{
		string key;
		int value;
		Node* prev;
		Node* next;
		~Node(){
			cout << "deleting " << key << ": " << value << endl;
			delete next;
		}
	};

	// float arr[3];

    // // declare pointer variable
    // float *ptr;
    
    // cout << "Displaying address using arrays: " << endl;

    // // use for loop to print addresses of all array elements
    // for (int i = 0; i < 3; ++i)
    // {
    //     cout << "&arr[" << i << "] = " << &arr[i] << endl;
    // }

    // // ptr = &arr[0]
    // ptr = arr;

    // cout<<"\nDisplaying address using pointers: "<< endl;

    // // use for loop to print addresses of all array elements
    // // using pointer notation
    // for (int i = 0; i < 3; ++i)
    // {
    //     cout << "ptr + " << i << " = "<< ptr + i << endl;
    // }

	int COUNT = 10;
	// int arr[COUNT];
	// int*intptr = arr;
	// for(int i = 0; i < COUNT; i++){

	// 	cout << (intptr+i) << endl;


	// }
	

	// Node firstNode;
	// firstNode.key = "hello";
	// firstNode.value = 0;
	// firstNode.next = new Node();
	// firstNode.next->key = "world";
	// firstNode.next->value = 1;
	// cout << "first node:" << endl;
	// cout << firstNode.key << ": " << firstNode.value << endl;
	// cout << "second node:" << endl;
	// cout << firstNode.next->key << ": " << firstNode.next->value << endl;

	Node**bucket_pointer;
	Node* buckets[COUNT];
	bucket_pointer = buckets;
	for(int i =0; i < COUNT; i++){
		stringstream ss;
		ss << i;
		Node* n = new Node();
		n->key = ss.str();
		n->value = i;
		buckets[i] = n;
		ss.str("");
	}

	for(int i = 0; i < COUNT; i++){
		cout << "[" << i << "] ";
		Node* curr = buckets[i];
		while(curr != NULL){
			cout << curr->key << ": " << curr->value;
			if(curr->next != NULL){
				cout << ", ";
			}
			curr = curr->next;
		}
		cout << endl;
	}


	return 0;
}
