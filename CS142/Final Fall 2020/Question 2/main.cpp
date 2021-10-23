#include <iostream>
#include <vector>
using namespace std;

void RemoveEvenNumbers(vector<int> & numbers);

int main(){
    vector<int> numbers;
    for(int i = 0; i < 11; i++){
        numbers.push_back(i);
        cout << i << endl;
    }

    RemoveEvenNumbers(numbers);
    for(int i = 0; i < numbers.size(); i++){
        cout << numbers.at(i) << endl;
    }

    return 0;
}

void RemoveEvenNumbers(vector<int> & numbers){
    for(int i = 0; i < numbers.size(); i++){
        if(numbers.at(i)%2 == 0){
            numbers.erase(numbers.begin() + i);
            i--;
        }
    }
}