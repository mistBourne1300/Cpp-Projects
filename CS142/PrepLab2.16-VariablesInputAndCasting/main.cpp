#include <iostream>
#include <string>      // Supports use of "string" data type
using namespace std;

int main() {
    int    userInt = 0;
    double userDouble = 0.0;
    char userCharacter = ' ';
    string userString;

    cout << "Enter integer: ";
    cin  >> userInt;
    cout << endl;

    cout << "Enter double: ";
    cin >> userDouble;
    cout << endl;

    cout << "Enter character: ";
    cin >> userCharacter;
    cout << endl;

    cout << "Enter string: ";
    cin >> userString;
    cout << endl;

    cout << userInt << " " << userDouble << " " << userCharacter << " " << userString << endl;
    cout << userString << " " << userCharacter << " " << userDouble << " " << userInt << endl;

    cout << userDouble << " cast to an integer is " << static_cast<int>(userDouble) << endl;

    return 0;
}