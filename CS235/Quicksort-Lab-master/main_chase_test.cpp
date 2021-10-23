#include "QS.cpp"

int main(){
	int array[] = {0,2,4,1,5,3,8,6,7,9};
	QS *sorter = new QS();

	sorter->createArray(10);
	cout << "uninitialized array: " << sorter->getArray() << endl;
	for (int i = 0; i < 10; i++){
		sorter->addToArray(array[i]);
	}
	cout << "size: " << sorter->getSize() << endl;

	cout << "array: " << sorter->getArray() << endl;

	sorter->sortAll();
	cout << "sorted: " << sorter->getArray() << endl;


}