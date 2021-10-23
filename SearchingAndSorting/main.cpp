#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
using namespace std;

double BubbleSort(vector<int> vectorToSort);

double SelectionSort(vector<int> vectorToSort);

double InsertionSort(vector<int> vectorToSort);

int Partition(vector<int>& vectorToSort, int low, int high);

void QuickSort(vector<int>& vectorToSort, int low, int high);

void Merge(vector<int>& vectorToSort, int low, int mid, int high);

void MergeSort(vector<int>& vectorToSort, int low, int high);

int main() {
    int numElements;
    ofstream outFS;
    ifstream inFS;
    const string FILE_NAME = "elements.txt";
    vector<int> vectorToSort;



    cout << "Hello, World!" << endl << "This program will sort a list using various methods." << endl
        << "Enter the number of elements to sort (the elements will be created randomly):";
    cin >> numElements;
    cout << endl << endl;

    cout << "initializing elements..." << endl;
    outFS.open(FILE_NAME);
    if(!outFS.is_open()){
        cout << "Failed to open file to write" << endl;
        return -1;
    }
    for (int i = 0; i < numElements; i++){
        outFS << ((rand()%numElements)+1) << " ";
    }
    outFS.close();


    cout << "elements initialized.";

    inFS.open(FILE_NAME);
    if(!inFS.is_open()){
        cout << "Failed to open file to read" << endl;
        return -1;
    }
    while (!inFS.eof()){
        int tempInt;
        inFS >> tempInt;
        vectorToSort.push_back(tempInt);
        ///comment out if the array is not to be output to the screen
        //cout << tempInt << " ";
    }
    inFS.close();
    cout << endl << endl << endl;


    cout << "Now we will sort this list from least to greatest" << endl << endl;

    if(numElements <= 20000){
        cout << "*********************************************************************************" << endl;
        cout << "Calling BubbleSort(){" << endl;
        double bubbleSortTime = BubbleSort(vectorToSort);
        cout << "}" << endl;
        cout << "Bubble sort took " << bubbleSortTime << " seconds." << endl;
        cout << "*********************************************************************************" << endl << endl;
    }else {
        cout << "Bubble sort skipped due to large input (n>20000)" << endl;
    }


    if(numElements <= 35000) {
        cout << "*********************************************************************************" << endl;
        cout << "Calling SelectionSort(){" << endl;
        double selectionSortTime = SelectionSort(vectorToSort);
        cout << "}" << endl;
        cout << "Selection sort took " << selectionSortTime << " seconds." << endl;
        cout << "*********************************************************************************" << endl << endl;





        cout << "*********************************************************************************" << endl;
        cout << "Calling InsertionSort(){" << endl;
        double insertionSortTime = InsertionSort(vectorToSort);
        cout << "}" << endl;
        cout << "Insertion sort took " << insertionSortTime << " seconds." << endl;
        cout << "*********************************************************************************" << endl << endl;
    }else {
        cout << "Insertion and selection sorts have been skipped, due to the large input (n>35000" << endl << endl;
    }

    if(numElements <= 1000000) {

        cout << "*********************************************************************************" << endl;
        cout << "Calling MergeSort(){" << endl;
        cout << "\t\tstarting timer..." << endl;
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        MergeSort(vectorToSort, 0, vectorToSort.size() - 1);
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        cout << "\t\ttimer ended." << endl;
        std::chrono::duration<double> algorithmComputeTime = std::chrono::duration_cast<std::chrono::duration<double> >(end - start);
        double mergeSortTime = algorithmComputeTime.count();
        cout << "}" << endl;
        cout << "Merge sort took " << mergeSortTime << " seconds." << endl;
        /*cout << "Double check that MergeSort() worked:" << endl;
        for (int i : vectorToSort){
            cout << i << " ";
        }
        cout << endl;*/
        cout << "*********************************************************************************" << endl << endl;

        cout << "Reimplementing the vector..." << endl;
        inFS.open(FILE_NAME);
        if (!inFS.is_open()) {
            cout << "Failed to open file to read" << endl;
            return -1;
        }
        int counter = 0;
        while (!inFS.eof()) {
            inFS >> vectorToSort.at(counter);
            counter++;
        }
        inFS.close();
        cout << "Vector recreated." << endl << endl;
    }else {
        cout << "Merge sort has been skipped, due to the large input (n>1000000)" << endl;
    }



    cout << "*********************************************************************************" << endl;
    cout << "Calling QuickSort(){" << endl;
    cout << "\t\tstarting timer..." << endl;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    QuickSort(vectorToSort, 0, vectorToSort.size() - 1);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    cout << "\t\ttimer ended." << endl;
    std::chrono::duration<double> algorithmComputeTime = std::chrono::duration_cast<std::chrono::duration<double> >(end - start);
    double quickSortTime = algorithmComputeTime.count();
    cout << "}" << endl;
    cout << "Quick sort took " << quickSortTime << " seconds." << endl;
    /*cout << "Double check that QuickSort() worked:" << endl;
    for (int i : vectorToSort){
        cout << i << " ";
    }
    cout << endl;*/
    cout << "*********************************************************************************" << endl << endl;








    return 0;
}

double BubbleSort(vector<int> vectorToSort){
    using namespace std::chrono;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;

    cout << "\tbubble sorting begun..." << endl;
    start = chrono::high_resolution_clock::now();

    bool done = false;
    int temp;

    ///beginning of sorting algorithm
    while(!done){
        done = true;
        for(int i = 0; i < vectorToSort.size() - 1; i++){
            if(vectorToSort.at(i) > vectorToSort.at(i + 1)){
                temp = vectorToSort.at(i);
                vectorToSort.at(i) = vectorToSort.at(i + 1);
                vectorToSort.at(i + 1) = temp;
                done = false;
            }
        }
    }

    ///end of sort algorithm

    end = chrono::high_resolution_clock::now();
    cout << "\tsorting complete" << endl;
    /// comment out if you don't want the array to be printed to the screen
    /*
    cout << " printing array:" << endl;
    for (int i = 0; i < vectorToSort.size(); i++){
        cout << vectorToSort.at(i) << " ";
    }
    cout << endl;
     */
    /// end comment out section
    cout << "\treturning sort time." << endl;



    duration<double> algorithmComputeTime = duration_cast<duration<double> >(end - start);

    return algorithmComputeTime.count();
}

double SelectionSort(vector<int> vectorToSort){
    using namespace std::chrono;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;

    cout << "\tselection sorting begun..." << endl;
    start = chrono::high_resolution_clock::now();

    ///beginning of sort function
    for(unsigned int i = 0; i < vectorToSort.size(); i++){
        int smallestIndex = i;
        //go through the unsorted vector and find the smallest value
        for (unsigned int j = i+1; j < vectorToSort.size(); j++){
            if(vectorToSort.at(j) < vectorToSort.at(smallestIndex)){
                smallestIndex = j;
            }
        }

        //swap values
        int temp = vectorToSort.at(i);
        vectorToSort.at(i) = vectorToSort.at(smallestIndex);
        vectorToSort.at(smallestIndex) = temp;

        //print vector. comment out if you don't want to see each iteration of the sorting algorithm
        //mostly for debugging purposes
        /*
        for (int i : vectorToSort){
            cout << i << " ";
        }
        cout << endl;
         */

    }
    ///end of sort function

    end = chrono::high_resolution_clock::now();
    cout << "\tsorting complete" << endl;
    /// comment out if you don't want the array to be printed to the screen
    /*
    cout << " printing array:" << endl;
    for (int i = 0; i < vectorToSort.size(); i++){
        cout << vectorToSort.at(i) << " ";
    }
    cout << endl;
     */
    /// end comment out section
    cout << "\treturning sort time." << endl;



    duration<double> algorithmComputeTime = duration_cast<duration<double> >(end - start);

    return algorithmComputeTime.count();
}

double InsertionSort(vector<int> vectorToSort){
    using namespace std::chrono;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;

    cout << "\tinsertion sorting begun..." << endl;
    start = chrono::high_resolution_clock::now();


    ///beginning of sort function
    int j;
    int temp;
    for (int i = 1; i < vectorToSort.size(); i++){
        j = i;

        while(j > 0 && vectorToSort.at(j) < vectorToSort.at(j - 1)){
            //swap values
            temp = vectorToSort.at(j);
            vectorToSort.at(j) = vectorToSort.at(j-1);
            vectorToSort.at(j-1) = temp;
            j--;
        }

        //print vector. comment out if you don't want to see each iteration of the sorting algorithm
        //mostly for debugging purposes
        /*
        for (int i : vectorToSort){
            cout << i << " ";
        }
        cout << endl;
        */
    }
    ///end of sort function


    end = chrono::high_resolution_clock::now();
    cout << "\tsorting complete" << endl;
    /// comment out if you don't want the array to be printed to the screen
    /*
    cout << " printing array:" << endl;
    for (int i = 0; i < vectorToSort.size(); i++){
        cout << vectorToSort.at(i) << " ";
    }
    cout << endl;
     */

    /// end comment out section
    cout << "\treturning sort time." << endl;



    duration<double> algorithmComputeTime = duration_cast<duration<double> >(end - start);

    return algorithmComputeTime.count();
}

int Partition(vector<int>& vectorToSort, int low, int high){
    int l, h, midpoint, pivot, temp;
    bool done;

    midpoint = low + ((high - low) / 2);

    pivot = vectorToSort.at(midpoint);

    done = false;
    l = low;
    h = high;

    while(!done){
        //increment l while less than the pivot
        while(vectorToSort.at(l) < pivot){
            l++;
        }

        //decrement h while less than the pivot
        while(vectorToSort.at(h) > pivot){
            h--;
        }

        if(l >= h){
            done = true;
        }else{
            //swap vector.at(l) and vector.at(h)
            //update l and h
            temp = vectorToSort.at(l);
            vectorToSort.at(l) = vectorToSort.at(h);
            vectorToSort.at(h) = temp;

            l++;
            h--;
        }
    }
    return h;
}

void QuickSort(vector<int>& vectorToSort, int low, int high){
    ///beginning of sort program
    if(low >= high){
        return;
    }

    //partition the vector into high and low
    int highOfLow = Partition(vectorToSort, low, high);

    //recursively sort the partitions
    QuickSort(vectorToSort, low, highOfLow);
    QuickSort(vectorToSort, highOfLow + 1, high);
    ///end of sort program
}

void Merge(vector<int>& vectorToSort, int low, int mid, int high){
    int mergePos, leftPos, rightPos, mergedSize;
    vector<int> mergedVector;

    mergePos = 0;
    mergedSize = (high - low) + 1;
    leftPos = low;
    rightPos = mid + 1;

    //add smallest element from left or right position to merged numbers.
    while(leftPos <= mid && rightPos <= high){
        if(vectorToSort.at(leftPos) < vectorToSort.at(rightPos)){
            mergedVector.push_back(vectorToSort.at(leftPos));
            leftPos++;
        }else {
            mergedVector.push_back(vectorToSort.at(rightPos));
            rightPos++;
        }
    }

    //if the left partition is not empty, add the remaining elements to the mergedVector
    while(leftPos <= mid){
        mergedVector.push_back(vectorToSort.at(leftPos));
        leftPos++;
    }

    while(rightPos <= high){
        mergedVector.push_back(vectorToSort.at(rightPos));
        rightPos++;
    }

    for(mergePos = 0; mergePos < mergedSize; mergePos++){
        vectorToSort.at(low + mergePos) = mergedVector.at(0);
        mergedVector.erase(mergedVector.begin());
    }


}

void MergeSort(vector<int>& vectorToSort, int low, int high){
    int midpoint;

    if(low < high){
        midpoint = (low + high) / 2;

        MergeSort(vectorToSort, low, midpoint);
        MergeSort(vectorToSort, midpoint + 1, high);

        Merge(vectorToSort, low, midpoint, high);
    }
}