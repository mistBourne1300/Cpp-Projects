#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "ERROR: palin requires exactly one positional argument" << endl;
        return 1;
    }
    string trypal = argv[1];
    for(int i = 0; i < trypal.size(); i++){
        trypal[i] = tolower(trypal[i]);
        if(!isalpha(trypal[i])){
            trypal.erase(trypal.begin()+i);
            i--;
        }
    }

    stack<char> mychars;
    for(int i = 0; i < trypal.length(); i++) {
        mychars.push(trypal[i]);
    }
    bool ispal = true;
    for(int i = 0; i < trypal.length(); i++) {
        char next = mychars.top();
        mychars.pop();
        cout << "Comparing "<<trypal[i]<<" "<<next<<endl;
        if(trypal[i] != next) {
            cout << "Not a Palindrome"<<endl;
            ispal = false;
            break;
        }
    }
    if(ispal) {
        cout << "Is a Palindrome";
    }

}
