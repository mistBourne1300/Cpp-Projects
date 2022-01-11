#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int FindMax(int myArray[], int arrSize);

int GuessMax(int myArray[], int arrSize);

double FindPercentage(bool myArr[], int arrSize);

int main() {
    const int HIGH_NUM = 1000;
    srand(time(0));
    int arrSize;
    int i;
    int arrayMax;
    char goOn = 'y';

    cout << "\n\n\nWe are going to play a game. In this game, you will try to find the highest by quitting. "
        << "The number you quit on becomes your guess. Thus, keep going until you believe you have found "
        << "the highest integer in the array. The highest possible number to have is " << RAND_MAX << endl
        << "To begin, please enter the number of items you want in your array: ";
    cin >> arrSize;
    cout << endl;


    int myArray[arrSize];

    for (i = 0; i < arrSize; i++){
        myArray[i] = rand();
        //cout << myArray[i] << ", ";
    }
    arrayMax = FindMax(myArray, arrSize);
    cout << endl;
    i = 0;
    while ((goOn != 'q') && (i < (arrSize - 1))){
        cout << "Number " << (i+1) << ": " << myArray[i] << endl
            << "Press 'q' to quit, anything else to continue." << endl
            << "Do you wish to continue?";
        cin >> goOn;
        if (goOn == 'q'){
            break;
        }
        cout << endl;
        i++;
    }
    cout << endl << endl << "You chose number " << (i+1) << ": " << myArray[i] << endl;

    cout << "The max was: " << arrayMax << endl;

    cout << "The computer's guess is: " << GuessMax(myArray, arrSize) << endl << endl << endl;

    int numSims;

    cout << "Now, the computer will simulate many iterations of this game using the optimal stopping theory." << endl
        << "Enter the number of items you would like in each array: ";
    cin >> arrSize;
    cout << endl << "Now enter the number of simulations to run: ";
    cin >> numSims;
    cout << endl;

    bool wonArr[numSims];


    for (i = 0; i < numSims; i++){
        int simArray[arrSize];
        int compGuess;


        //populate simArray
        for (int j = 0; j < arrSize; j++){
            simArray[j] = rand();
            //cout << myArray[i] << ", ";
        }

        compGuess = GuessMax(simArray, arrSize);

        arrayMax = FindMax(simArray, arrSize);

        wonArr[i] = (compGuess == arrayMax);
        cout << wonArr[i] << " " << flush;
    }

    cout << endl << "^^ This is the boolean array of how many times the computer guessed right..." << endl;

    /*for (i = 0; i < numSims; i++){
        if (i < numSims - 1){
            cout << wonArr[i] << ", ";
        }else {
            cout << wonArr[i] << endl;
        }
    }*/
    cout << endl;
    cout << "That is, the computer guessed correctly " << (FindPercentage(wonArr, numSims) * 100) << "% of the time." << endl;


}

int FindMax(int myArray[], int arrSize){
    int maxNum = myArray[0];
    for (int i = 0; i < arrSize; i++){
        if (myArray[i] > maxNum){
            maxNum = myArray[i];
        }
    }
    return maxNum;
}

int GuessMax(int myArray[], int arrSize){
    /*for (int i = 0; i < arrSize; i++){
        cout << myArray[i] << ", ";
    }*/
    //cout << endl;
    int myGuess;
    double euler = exp(1);
    int sampleSize = ceil(arrSize / euler);
    int maxSoFar = myArray[0];

    //cout << "sampleSize: " << sampleSize << endl;
    int i;
    for (i = 0; i < sampleSize; i++){
        if (maxSoFar < myArray[i]) {
            maxSoFar = myArray[i];
        }
    }
    //cout << "maxSoFar: " << maxSoFar << endl;
    i = sampleSize;
    myGuess = myArray[i];
    while ((myGuess <= maxSoFar) && (i < arrSize)){
        myGuess = myArray[i];
        //cout << "myGuess: " << myGuess << endl;
        i++;
    }
    return myGuess;
}

double FindPercentage(bool myArr[], int arrSize){
    int numTrue = 0;
    for (int i = 0; i < arrSize; i++){
        if (myArr[i]){
            numTrue++;
            //cout << "found truth" << endl;
        }
    }
    return static_cast<double>(numTrue) / arrSize;
}