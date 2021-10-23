#include <iostream>

using namespace std;

int main() {
    int myEcho;

    cout << "enter something for me to say: ";
    cin >> myEcho;
    //cout << myEcho;

    for(int i = 0; i<10; i++){
        cout << myEcho * i << endl;
    }

}

