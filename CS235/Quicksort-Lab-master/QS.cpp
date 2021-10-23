#pragma once

#include "QS.h"


void QS::clear(){
	delete array;
	array = NULL;
	capacity = 0;
	addindex = 0;
}

bool QS::createArray(int capacity){
	if(capacity <= 0){
		return 0;
	}
	if(array != NULL){
		delete array;
		array = NULL;
	}
	array = new int[capacity];
	this->capacity = capacity;
	addindex = 0;
	return true;
}

bool QS::addToArray(int value){
	if(addindex >= capacity){
		cout << "did not add to array " << addindex << " >= " << capacity << endl;
		return 0;
	}
	array[addindex] = value;
	addindex++;
	return 1;
}

string QS::getArray() const{
	if(array == NULL){
		return "";
	}
	ostringstream return_string;
	return_string << "";
	for(int i = 0; i < getSize(); i++){
		if(i == getSize() - 1){
			return_string << array[i];
		}
		else{
			return_string << array[i] << ",";
		}
	}
	return return_string.str();
}

int QS::getSize() const{
	return addindex;
}

void QS::exchange(int index1, int index2){
	if(index1 >= getSize() || index2 >= getSize() || index1 < 0 || index2 < 0){
		cout << "cannot exchange, index out of range" << endl;
		return;
	}
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
	cout << "array(after exchange): " << getArray() << endl;
	return;
}

int QS::partition(int left, int right, int partition){
	if(array == NULL){
		return -1;
	}
	if(left < 0 || left >= getSize() || right < 0 || right >= getSize() || left >= right || partition < left || partition > right){
		return -1;
	}
	cout << "array before partition: " << getArray() << endl;
	cout << "exchanging left(" << left << ") and partition(" << partition << ")" << endl;
	exchange(left, partition);
	int up = left + 1;
	int down = right;
	bool done = false;
	int pivot = array[0];
	while(!done){
		while(array[up] < pivot){
			up++;
		}
		while(array[down] > pivot){
			down--;
		}
		if(up>=down){
			done = true;
		}else{
			exchange(up, down);
			up++;
			down--;
		}
	}
	cout << "exchanging left(" << left << ") and down(" << down << ")" << endl;
	exchange(left, down);
	cout << "array after partition: " << getArray() << endl;
	return down;
}

int QS::medianOfThree(int left, int right){
	cout << "accessed medianOfThree(" << left << ", " << right << ")" << endl;
	if(array == NULL || left < 0 || left >= getSize() || right < 0 || right >= getSize() || left > right){
		return -1;
	}
	int median = left + ((right+left)/2);
	if(array[right] < array[median]){
		cout << "exchanging right(" << right << ") and median(" << median << ")" << endl;
		exchange(right, median);
	}
	if(array[median] < array[left]){
		cout << "exchanging median(" << median << " and left(" << left << ")" << endl;
		exchange(median, left);
	}
	if(array[right] < array[median]){
		cout << "exchanging right(" << right << "and median(" << ")" << endl;
		exchange(right, median);
	}
	return median;
}

void QS::sortAll(){
	cout << "accessed sortAll()" << endl;
	quicksort(0,getSize() - 1);
}

void QS::quicksort(int left, int right){
	cout << "accessed quicksort(" << left << ", " << right << ")" << endl;
	if(left >= right){
		return;
	}
	int median = medianOfThree(left, right);
	cout << "median: " << median << endl;
	if(median < 0 || median >= getSize()){
		return;
	}
	
	partition(left, right, median);
	quicksort(left, median);
	quicksort(right, median);
}