#include "Hashmap.h"
#include <sstream>
using namespace std;

int main(){
	ostringstream outss;
	Hashmap mymap;
	for(int i = 0; i < 100; i++){
		outss << i;
		// cout << "adding " << outss.str() << endl;
		mymap[outss.str()] = i;
		// cout << mymap.toString() << endl;
		//outss.str("");
		// cout << outss.str();
		outss.str("");
	}
	cout << mymap.toString() << endl;
	// cout << "size: " << mymap.size() << endl;
	// cout << mymap.remove("01234567") << endl;
	// cout << "size: " << mymap.size() << endl;
	// cout << mymap.toSortedString() << endl;
	mymap.clear();
	cout << mymap.toString() << endl;
}