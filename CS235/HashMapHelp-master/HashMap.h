#include <iostream>
#include <vector>
using namespace std;

const int CONSIZE=10;
int hashme(string param, int tablesize) {
    int sum = 0;
    for(int i = 0; i < param.size(); i++) {
        sum += param[i];
    }
    int hashval = sum%tablesize;
    //cout << "Size = "<<sizeof(param)<<" Sum = "<<sum<<" hash "<<hashval<<endl;
    return hashval;
}
template <class Name, class Value>
class HashMap {
	private:
	struct node {
		pair<Name, Value> context;
		node *next;
	};
	
	node *context_array[CONSIZE];
	
	public:
	HashMap() {
		for(int i = 0; i < CONSIZE; i++) {
			context_array[i] = NULL;
		}
	}
	Value &operator[](Name opname) {
		return at(opname);
	}
	
	Value &at(Name name) {
		int hashval = hashme(name, CONSIZE); // Compute the hash value for this name, for now assume it is 0
		node *ptr = context_array[hashval];
		while(ptr != NULL) {
			// cout <<"comparing "<<name<<" first "<<ptr->context.first<<endl;
			if(name == ptr->context.first) { // We found it
				break;
			} else {
			  //cout << "ptr"<< ptr<<"next "<< ptr->next<<endl;
			  ptr = ptr->next;
			}
		}
		if(ptr == NULL) { // We need to create a new node, put it on the front of the list
			ptr = new node;
			//cout << "new node "<< static_cast<void*>(&(ptr->context.second))<<endl;
			ptr->next = context_array[hashval];
			context_array[hashval] = ptr;
			ptr->context.first = name;
		}
		//cout << "return "<< static_cast<void*>(&(ptr->context.second))<<endl;
		return(ptr->context.second);
	}
};
