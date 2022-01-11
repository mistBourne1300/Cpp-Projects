#include "Hashmap.h"

unsigned int Hashmap::hash(string key) const{
	unsigned int hashvalue = 0;
	for(int i = 0; i < key.length(); i++){
		hashvalue += key[i] * 13^i;
	}
	return hashvalue % curr_buckets;
}

Hashmap::Hashmap(){
	mapSize = 0;
	for(int i = 0; i < curr_buckets; i++){
		buckets[i] = NULL;
	}

}

Hashmap::~Hashmap(){
	for(int i = 0; i < curr_buckets; i++){
		delete buckets[i];
	}
}

void Hashmap::insert(string key, int value){
	this->operator[](key) = value;
}

bool Hashmap::contains(string key) const{  
	unsigned int hashvalue = hash(key);
	Node* curr_node = buckets[hashvalue];
	while(curr_node != NULL){
		if(curr_node->key == key){
			return true;
		}
		curr_node = curr_node->next;
	}
	return false;
} 

int Hashmap::get(string key) const{
	unsigned int hashvalue = hash(key);
	Node* curr_node = buckets[hashvalue];
	while(curr_node != NULL){
		if(curr_node->key == key){
			return curr_node->value;
		}
		curr_node = curr_node->next;
	}
	throw std::invalid_argument("Argument for get() function invalid: key not found");
}

int& Hashmap::operator [](string key){
	//cout << "accessed operator[]" << endl;
	unsigned int hashvalue = hash(key);
	Node* node = buckets[hashvalue];
	// find the node with the key, if it exists
	while(node != NULL){
		if(node->key == key){
			break;
		} else {
			node = node->next;
		}
	}

	// if the node was not found, we need to create it
	if(node == NULL){
		node = new Node();
		node->next = buckets[hashvalue];
		node->key = key;
		if(buckets[hashvalue] != NULL){
			buckets[hashvalue]->prev = node;
		}
		buckets[hashvalue] = node;
		mapSize++;
	}

	return node->value;
}

bool Hashmap::remove(string key){
	unsigned int hashvalue = hash(key);
	Node* curr_node = buckets[hashvalue];
	while(curr_node != NULL){
		// curr_node is the node to remove
		cout << curr_node->key << ":" << key << endl;
		if(curr_node->key == key){
			Node* prev = curr_node->prev; //check to see if curr_node is the first or last in the list
			Node* next = curr_node->next;
			// node is first in the list
			if(prev == NULL){
				buckets[hashvalue] = next;
			}else{
				prev->next = next;
			}
			// node is not last
			if(next != NULL){
				next->prev = prev;
			}
			curr_node->next = NULL;
			delete curr_node;
			mapSize--;
			return true;
		}
		curr_node = curr_node->next;
	}
	return false;
}

void Hashmap::clear(){
	for(int i = 0; i < curr_buckets; i++){
		Node* node = buckets[i];
		buckets[i] = NULL;
		delete node;
	}
	mapSize = 0;
}

string Hashmap::toString() const{
	cout << "accessed toString()" << endl;
	ostringstream outss;
	for(int i = 0; i < curr_buckets; i++){
		outss << "[" << i << "] ";
		Node* curr_node = buckets[i];
		while(curr_node != NULL){
			outss << curr_node->key << " => " << curr_node->value;
			if(curr_node->next != NULL){
				outss << ", ";
			}
			curr_node = curr_node->next;
		}
		outss << "\n";
	}
	return outss.str();
}

int Hashmap::size() const{
	return mapSize;
}

string Hashmap::toSortedString() const{
	priority_queue<Node*, vector<Node*>, NodeCompare> queueing;
	for(int i = 0; i < curr_buckets; i++){
		Node* curr_node = buckets[i];
		while(curr_node != NULL){
			queueing.push(curr_node);
			curr_node = curr_node->next;
		}
	}
	stringstream ss;
	while(!queueing.empty()){
		Node* top = queueing.top(); // Get top node (next node in sorted order)
    	ss << top->key << " => " << top->value << endl; // Add node data to stringstream
    	queueing.pop(); // Pop it off
	}
	return ss.str();
}

// void Hashmap::rehash(){
// 	// no need to rehash
// 	if((double)mapSize/(double)curr_buckets < .75){
// 		return;
// 	}
// 	int old_buckets = curr_buckets;
// 	curr_buckets*=2;
// 	Node** old_bucket_arr = buckets;


// 	Node* newBuckets[curr_buckets];
// 	for(int i =0 ; i < old_buckets; i++){
// 		Node* curr_node = buckets[i];
// 		while(curr_node != NULL){
// 			Node* next_node = curr_node->next; // save the next node
// 			unsigned int hashvalue = hash(curr_node->key); // get the hashvalue of the 
// 			curr_node->next = buckets[hashvalue]; // reassign curr->next to be the current resident of buckets[hash]
// 			// if the buckets[hash] exists, reassign its prev pointer
// 			if(buckets[hashvalue] != NULL){
// 				buckets[hashvalue]->prev = curr_node;
// 			}
// 			buckets[hashvalue] = curr_node; // reassign the buskets[hash] to curr
// 			curr_node = next_node; // grab the next node that was saved previously
// 		}
// 	}
// 	delete buckets;
// 	buckets = newBuckets;
// }