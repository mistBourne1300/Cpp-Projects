#include <iostream>
using namespace std;

int main() {
    int userInt1, userInt2;
    cout << "Enter integer: ";
    cin >> userInt1;
    cout << endl;

    cout << "You entered: " << userInt1 << endl;
    cout << userInt1 << " squared is " << (userInt1 * userInt1) << endl;
    cout << "And " << userInt1 << " cubed is " << (userInt1 * userInt1 * userInt1) << "!!" << endl;

    cout << "Enter another integer: ";
    cin >> userInt2;
    cout << endl;

    cout << userInt1 << " + " << userInt2 << " is " << (userInt1 + userInt2) << endl;
    cout << userInt1 << " * " << userInt2 << " is " << (userInt1 * userInt2) << endl;



    return 0;
}
