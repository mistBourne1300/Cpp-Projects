#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> vectorToPrint){
    for(int i = 0; i < vectorToPrint.size(); i++){
        cout << vectorToPrint.at(i) << endl;
    }
}

void ReverseVector(vector<int>& vectorToReverse){
    int vectorSize = vectorToReverse.size();
    for(int i = 0; i < vectorSize/2; i++){
        int temp = vectorToReverse.at(i);
        vectorToReverse.at(i) = vectorToReverse.at(vectorSize-i-1);
        vectorToReverse.at(vectorSize-i-1) = temp;
    }
}

int main() {
    int vectorSize = 0, multiplier = 0;
    vector<int> userVector;
    cin >> vectorSize >> multiplier;
    for(int i = 0; i < vectorSize; i++){
        userVector.push_back(i*multiplier);
    }
    PrintVector(userVector);
    ReverseVector(userVector);
    PrintVector(userVector);


    return 0;
}