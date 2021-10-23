#include "LinkedList.cpp"

int main(){
	LinkedList<int> mylist;
	mylist.insertTail(1);
	mylist.insertHead(1);
	cout << mylist.toString() << endl;
}