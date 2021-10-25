#include "BST.cpp"
#include <vector>
#include <random>
using namespace std;

int main(){
	vector<int> testvect;
	BST bst;
	for(int i = 1; i < 10; i++){
		//cout << "adding " << i << endl;
		testvect.push_back(i);
	}
	int index = 0;
	while(!testvect.empty()){
		index = random() % testvect.size();
		bst.add(testvect.at(index));
		testvect.erase(testvect.begin() + index);
	}
	cout << "attempting add(10):\n" << bst.add(10) << endl;
	cout << "attempting add(11):\n" << bst.add(10) << endl;
	bst.print();
	cout << "enter anything to continue: ";
	string anything;
	cin >> anything;
	cout << bst.getRootNode()->getData() << endl;
	cout << "done" << endl;
}