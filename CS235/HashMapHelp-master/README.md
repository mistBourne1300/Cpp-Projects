# HashMapHelp
I hope that this learning activity provides a capstone for the whole class.  You will be building a hashmap for the linguistic problem you solved in Lab #3.  You should be able to see the real differences that occur when you pick the correct data structure.  I also hope that this tutorial will help you with the hashmap lab (hint hint, most of the coding is done for you in this lab).

First, lets instrument the main function so that it will time the hashmap version and the vectormap version of the lab.  We will use this code to compare the time it takes to put strings into a map built from a vector vs one built from a hash.

hashmap.cpp
```c++
...
#include <ctime>
#include <stdlib.h>
#include <math.h>
...
  clock_t oldtime, newtime; // To time the functions
  double seconds;
  oldtime = clock();
  ...
  newtime = clock();
  seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
  cout << "Vector Map took "<<seconds<<endl;
```
And lets integrate this into the working 
[driver function](https://github.com/BYUCS235/HashMapHelp/blob/master/hashmap.cpp).  First we will read the strings from 1Nephi into a list.

hashmap.cpp
```c++
// Read data
  while (!file.eof()) {
    string word, nopunct="";
    file >> word;
    
    for(auto &c : word) { // Remove Punctuation      
      if (isalpha(c)) {
        nopunct +=c;       
      }
    }
    lst.push_back(nopunct);
  }
```
Then we will push the data from the list into a map that we have created.  When we look up 'state' in the VectorMap, it will look through the vector one entry at a time until it finds the entry matching 'state'.  Then it returns a reference to a list at that position and we push the string from the list corresponding to 'state'.

hashmap.cpp
```c++
VectorMap<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    //vector<string> tmp = wordmap[state];
    //cout <<"Got "<< tmp<<endl;
    state = *it;
  }
```
Now, lets take the code we discussed for 
[operator overloading](https://github.com/BYUCS235/OperatorOverloading/blob/master/map.cpp)
and add the hash function into HashMap.h.  It turns out that when you say 'mymap["key"].push_back(value)', you are actually calling a function named "[]" passing it the parameter "key".  We will then use the "at" function to look up that key in the underlying data structure and return a reference to the list.  We will do this for both a vector and a hash into a vector.

HashMap.h
```c++
	Value &operator[](Name opname) {
		return at(opname);
	}
	
	Value &at(Name name) {
		int hashval = 0; // Compute the hash value for this name, for now assume it is 0
		node *ptr = context_array[hashval];
		while(ptr != NULL) {
			cout <<"comparing "<<name<<" first "<<ptr->context.first<<endl;
			if(name == ptr->context.first) { // We found it
				break;
			} else {
			  cout << "ptr"<< ptr<<"next "<< ptr->next<<endl;
			  ptr = ptr->next;
			}
		}
		if(ptr == NULL) { // We need to create a new node, put it on the front of the list
			ptr = new node;
			cout << "new node "<< static_cast<void*>(&(ptr->context.second))<<endl;
			ptr->next = context_array[hashval];
			context_array[hashval] = ptr;
			ptr->context.first = name;
		}
		cout << "return "<< static_cast<void*>(&(ptr->context.second))<<endl;
		return(ptr->context.second);
	}
```
Instead of using index zero every time
```c++
	int hashval = 0; // Compute the hash value for this name, for now assume it is 0
  node *ptr = context_array[hashval];
```
Call the 
[hash function](https://github.com/BYUCS235/HashDetails/blob/master/hash.cpp)
we discussed before.
```c++
	int hashval = hashme(name, CONSIZE); // Compute the hash value for this name, for now assume it is 0
	node *ptr = context_array[hashval];
```
Add the code for the 
[VectorMap](https://github.com/BYUCS235/OperatorOverloading/blob/master/VectorMap.h) 
that we developed earlier into VectorMap.h and the code should compile.

Now lets compare times on 1Nephi.txt and poe.txt (poe.txt has more words, so n is larger).
```
$ ./hashmap 1Nephi.txt
...
Vector Map took 0.114983
...
Hash Map took 0.044118
```
So, the vector implementation took nearly three times as long to do the same thing.  When we try the same program with poe.txt which has more words:
```
$ ./hashmap poe.txt
...
Vector Map took 1.55767
...
Hash Map took 0.551441
```

Try changing the number of words that you create so that the test takes enough time to see a difference.
```c++
for (int i = 0; i < 10000; i++) {
    int ind = rand() % wordmap[state].size();
```
The code in this repository should really help you in the hashmap lab.
