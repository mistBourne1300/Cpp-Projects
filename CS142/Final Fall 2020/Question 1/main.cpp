#include <iostream>

void PrintForward(int arrayToPrint[], int arraySize);
void PrintBackward(int arrayToPrint[], int arraySize);

int main() {
    const int ARRAY_SIZE = 10;
    int multipleArray[ARRAY_SIZE];
    int multiplier = 0;
    std::cin >> multiplier;
    for(int i = 0; i < ARRAY_SIZE; i++){
        multipleArray[i] = i * multiplier;
    }
    PrintForward(multipleArray, ARRAY_SIZE);
    PrintBackward(multipleArray, ARRAY_SIZE);
}

void PrintForward(int arrayToPrint[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        std::cout << arrayToPrint[i] << std::endl;
    }
}

void PrintBackward(int arrayToPrint[], int arraySize){
    for(int i = arraySize - 1; i >= 0; i--){
        std::cout << arrayToPrint[i] << std::endl;
    }
}