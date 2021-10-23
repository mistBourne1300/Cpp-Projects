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

    const string BFF = "best friend forever";
    const string IDK = "I don't know";
    const string JK = "just kidding";
    const string TMI = "too much information";
    const string TTYL = "talk to you later";

    const int BFF_LENGTH = 3;
    const int IDK_LENGTH = 3;
    const int JK_LENGTH = 2;
    const int TMI_LENGTH = 3;
    const int TTYL_LENGTH = 4;

    int index = 0;

    cout << "Enter text: ";
    getline(cin, userInput);
    cout << endl;

    cout << "You entered: " << userInput << endl;

    if (userInput.find("BFF") != string::npos){
        index = userInput.find("BFF");
        userInput.replace(index, BFF_LENGTH, BFF);
    }

    if (userInput.find("IDK") != string::npos){
        index = userInput.find("IDK");
        userInput.replace(index, IDK_LENGTH, IDK);
    }

    if (userInput.find("JK") != string::npos){
        index = userInput.find("JK");
        userInput.replace(index, JK_LENGTH, JK);
    }

    if (userInput.find("TMI") != string::npos){
        index = userInput.find("TMI");
        userInput.replace(index, TMI_LENGTH, TMI);
    }

    if (userInput.find("TTYL") != string::npos){
        index = userInput.find("TTYL");
        userInput.replace(index, TTYL_LENGTH, TTYL);
    }


    cout << "Expanded: " << userInput << endl;

    return 0;
}