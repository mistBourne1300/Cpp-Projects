#include <iostream>

using namespace std;
//  1 2 3 4 5 6 7 8 9 10

const int NUM_INTEGERS = 10;

int main(){

    int userInts [NUM_INTEGERS];
    for(int i = 0; i < NUM_INTEGERS; i++){
        cin >> userInts[i];
        if(userInts[i] % 2 == 0){
            userInts[i] = 1;
        }
        else{
            userInts[i] = 0;
        }
    }
    for(int i = NUM_INTEGERS-1; i >= 0; i--){
        cout << userInts[i] << endl;
    }



   return 0;
}