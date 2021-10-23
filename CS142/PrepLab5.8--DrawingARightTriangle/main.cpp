#include <iostream>
using namespace std;

int main() {
    char userChar = ' ';
    int triangleHeight = 0;

    cout << "Enter a character: ";
    cin >> userChar;
    cout << endl;

    cout << "Enter triangle height: ";
    cin >> triangleHeight;
    cout << endl;

    for (int i = 1; i <= triangleHeight; i++){
        for(int j = 1; j <= i; j++){
            cout << userChar << " ";
        }
        cout << endl;
    }

    return 0;
}
