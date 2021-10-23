#include <iostream>
#include <string>
using namespace std;

/*BFF -- best friend forever
IDK -- I don't know
JK -- just kidding
TMI -- too much information
TTYL -- talk to you later

IDK if I'll go. It's my BFF's birthday. Actually, JK, I need to get a colonoscopy. Sorry if TMI. TTYL!
*/

int main() {
    string userInput;
    cout << "Enter text: ";
    getline(cin, userInput);
    cout << endl;

    cout << "You entered: " << userInput << endl;

    if (userInput.find("BFF") != string::npos){
        cout << "BFF: best friend forever" << endl;
    }
    if (userInput.find("IDK") != string::npos){
        cout << "IDK: I don't know" << endl;
    }
    if (userInput.find("JK") != string::npos){
        cout << "JK: just kidding" << endl;
    }
    if (userInput.find("TMI") != string::npos){
        cout << "TMI: too much information" << endl;
    }
    if (userInput.find("TTYL") != string::npos){
        cout << "TTYL: talk to you later" << endl;
    }
    return 0;
}
