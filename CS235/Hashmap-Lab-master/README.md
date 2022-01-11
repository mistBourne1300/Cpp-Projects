# Hashmap Lab

## Briefing: 
Implement your own map using a hash table, like the C++ STL unordered\_map class. The goal is to get your insert, find, and remove functions to have an average runtime of O(1).

Every file you need is provided except Hashmap.cpp. You need to make Hashmap.cpp and implement the methods from Hashmap.h. You do not need to alter or add any other files, though you may choose to alter Hashmap.h in limited ways (such as adding additional private methods or changing the number of buckets used in your hash table).

The hash table you build will use chaining. Your primary structure is an array of Node\* where each entry starts off as NULL. The preprocessor define BUCKETS defines the number of buckets (the capacity of the array). When a node is placed into an empty bucket, that node becomes the head of the linked list chain for that bucket. When a node is placed into a bucket containing one or more nodes, the new node is chained into the linked list. Each entry of the array is essentially a head pointer of a doubly-linked list. There is no tail pointer. Each node has a prev pointer and a next pointer.

Each node in your hash table has both a key and a value. The key is a string and the value is an int. Keys must be unique, but more than one key can map to the same value. To determine which bucket a node should be placed into, use your hash function on the node's key. The return value (the hashcode) determines the index of your buckets array. Place the node into the linked list whose head is at buckets[hashcode].

Your hash table may look something like this once values are put into it:

* [0] Aylesbury => 1, Azikiwe => 1, azimuth => 1, azimuthally => 1
* [1] Azerbaijan => 1, azure => 1
* [2] Ayrshires => 1, Azeris => 1
* [3] azimuths => 1, Aztec => 1
* [4] Ayckbourn => 1, ayes => 1, Azerbaijans => 1
* [5] Ayckbourns => 1, Ayrs => 1
* [6] Ayers => 1, Azov => 1, Aztecan => 1, azures => 1
* [7] Aylesburys => 1, Ayrshire => 1, azaleas => 1, Azikiwes => 1
* [8] Azores => 1, Aztecs => 1
* [9] aye => 1, azimuthal => 1, Azizs => 1

In this case, all nodes have a value of 1 but each has a unique key. There are 10 buckets. The hash function distributed the nodes fairly evenly across the buckets. If your hash table looks more like this:

* [0] Aylesbury => 1, Azikiwe => 1, azimuth => 1, azimuthally => 1, Azerbaijan => 1, azure => 1
* [1]
* [2] Ayrshires => 1, Azeris => 1, azimuths => 1, Aztec => 1, Ayckbourn => 1, ayes => 1, Azerbaijans => 1
* [3]
* [4]
* [5]
* [6]
* [7]
* [8] Azores => 1, Aztecs => 1, Ayers => 1, Azov => 1, Aztecan => 1, azures => 1, aye => 1, azimuthal => 1, Azizs => 1
* [9] Ayckbourns => 1, Ayrs => 1, Aylesburys => 1, Ayrshire => 1, azaleas => 1, Azikiwes => 1

Then you may need to modify your hash function so that it distributes the keys more uniformly over the buckets. You might consider googling "good hash functions for strings" or combing through class readings to get some ideas of how to improve your hash function.

## File 1 - Insert and Get (10 pts)
### Constructor
* Initialize buckets[i] = NULL for each i (0 <= i < BUCKETS)
* Initialize size

### Insert
* The insert function takes in 2 parameters: string key and int value
* First, use your hash function to figure out which bucket (which index of your buckets array) the key belongs in
* Remember that buckets[hashcode] is a Node pointer that represents the head of your doubly-linked list for that bucket
* Iterate through all of the nodes in the list at buckets[hashcode] to see if the insert key is already in the map
* If you find a node with the input key already in the map, update that node's value to the new input value
* If you do not find a node with the input key, create a new node with the given key and value and insert the new node into the doubly linked list at buckets[hashcode]

### Get
* The get function takes in 1 parameter: string key
* First, use your hash function to figure out which bucket the key belongs in
* Iterate through all of the nodes in the list at buckets[hashcode] to find the node with the matching key
* If you find a node with a matching key, return that node's value
* If you don't find a node with a matching key, throw an invalid\_argument exception (http://www.cplusplus.com/reference/stdexcept/invalid_argument/)

### Size
* You'll also need your size function to return the number of nodes in the map
* Your map class should use a private member variable to keep track of size, make sure to update it when nodes are inserted and removed

### ToString
* For your own benefit, implement your toString method as described in HashmapInterface.h
* After each test file is read in and processed, the main.cpp test driver will print your toString result to show you the contents of your map

## File 2 - Insert and Contains (10 pts)
* The contains function takes in 1 parameter: string key
* Return true if the key is in the map, false otherwise
* Remember to start by using your hash function to figure out which bucket the key would be in if it was in the map

File 2 also performs additional tests on insert to make sure that your code can handle multiple inserts into a single bucket.

## File 3 - The [] operator (15 pts)
* For inserting a new key/value pair, getting value by key, or updating value by key
* The operator [] function returns an int& to allow all of these operations
* First, use your hash function to figure out which bucket the key belongs in
* If you find the node with the matching key in the map, then return that node's value (this will allow the caller to both get and update the value)
* If you do not find the node with the matching key in the map, insert a new node with the given key and a value of 0 into the appropriate bucket and return newNode-\>value

File 3 also performs additional tests on insert and get to make sure that insert can be used to overwrite values and that get will throw an invalid\_argument exception when the key isn't in the map. Also tests to make sure that multiple keys can be chained together in a single bucket.

## File 4 - Remove and Clear (20 pts)
### Remove
* The remove function takes in 1 parameter: string key
* Return true if key is found and removed, false otherwise
* Use the hash function to find which bucket to look into, then iterate through that bucket's linked list to find the node with the given key
* If the node isn't found, return false
* If the node is found, remove the node from the linked list (make sure to update buckets[hashcode] to point to the new head if the head is removed)
* Make sure to update all pointers (you can refer to your LinkedList lab code) and delete the removed node to deallocate memory
* Decrement size and return true

### Clear
* Iterate through all buckets
* For each bucket that is not null, iterate through the bucket's linked list and delete all the nodes
* Reset all buckets to null
* Reset size to 0

## File 5 - Everything Combined (10 pts)
* An intense test of everything (except for toSortedString)
* Intensive test of insert, get, contains, [] operator, remove, and clear

## File 6 - WordCounter and ToSortedString (20 pts)
* The WordCounter class is provided for you in its entirety
* The WordCounter class reads a text file and uses your Hashmap class to build a map from words to their frequency
* The WordCounter class toString method simply relies on the Hashmap toSortedString method, so that's all you need to do to get this test case to work (assuming your contains, [] operator, and clear methods already work)

### ToSortedString
* Hashmaps are unordered by nature, so you have to use a different data structure to sort your data
* For this lab, perform heapsort using a priority queue
* Create a priority queue to hold all of the Node pointers in your map
* Use the following syntax: priority\_queue\<Node\*, vector\<Node\*\>, NodeCompare\> nodeHeap;
* The first template parameter (Node\*) is the type of object that can be put into the priority queue
* The second template parameter (vector\<Node\*\>) is the underlying datatype for the priority queue's heap
* The third template parameter (NodeCompare) defines the comparison function used for sorting (see Hashmap.h struct NodeCompare)
* Iterate through all of the buckets. For each bucket, iterate through the linked list. Push every Node\* onto the priority queue (nodeHeap)
* While nodeHeap is not empty, add the top node's "key => value\n" to a stringstream (Don't forget to pop after using the top)
* Return the stringstream as a string

```C++
string Hashmap::toSortedString() const
{
  stringstream ss;
  priority_queue<Node*, vector<Node*>, NodeCompare> nodeHeap;
  for(int i = 0; i < BUCKETS; i++)
  {
    // Iterate through each bucket. Use nodeHeap.push to push all Node* onto heap.
  }
  while(!nodeHeap.empty())
  {
    Node* top = nodeHeap.top(); // Get top node (next node in sorted order)
    ss << top->key << " => " << top->value << endl; // Add node data to stringstream
    nodeHeap.pop(); // Pop it off
  }
  return ss.str();
}
```

## Valgrind (15 pts)
* No memory leaks at all
* No memory definitely lost, directly lost, indirectly lost, or possibly lost.
* Run "valgrind --leak-check=full ./lab9" to check with valgrind
* Don't always run tests with valgrind (some of these test cases process lots of data, so valgrind slows down the automated test cases considerably)
