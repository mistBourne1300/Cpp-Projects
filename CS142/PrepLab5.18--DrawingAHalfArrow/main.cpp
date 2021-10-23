#include <iostream>
using namespace std;

int main() {
    int arrowBaseHeight = 0;
    int arrowBaseWidth = 0;
    int arrowHeadWidth = 0;

    cout << "Enter arrow base height: " << endl;
    cin >> arrowBaseHeight;

    cout << "Enter arrow base width: " << endl;
    cin >> arrowBaseWidth;

    while (arrowHeadWidth <= arrowBaseWidth){
        cout << "Enter arrow head width: " << endl;
        cin >> arrowHeadWidth;
    }

    //printing arrow base
    for (int i = 0; i < arrowBaseHeight; i++){
        for(int j = 0; j < arrowBaseWidth; j++){
            cout << "*";
        }
        cout << endl;
    }

    //printing arrow head
    for(int i = arrowHeadWidth; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}
