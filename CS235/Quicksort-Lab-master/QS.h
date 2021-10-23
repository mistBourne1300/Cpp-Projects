#pragma once

#include <sstream>

#include "QSInterface.h"

class QS : public QSInterface{
private:
	int addindex;
	int* array;
	int capacity;
	void exchange(int index1, int index2);
	void quicksort(int left, int right);
public:
	void clear();
	bool createArray(int capacity);
	bool addToArray(int value);
	string getArray() const;
	int getSize() const;
	int partition(int left, int right, int pivotIndex);
	int medianOfThree(int left, int right);
	void sortAll();
	~QS(){
		delete array;
		array = NULL;
	}
};

