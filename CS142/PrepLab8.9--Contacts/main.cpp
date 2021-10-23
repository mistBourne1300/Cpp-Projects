#include <iostream>
#include <string>
using namespace std;
#include "Contacts.h"

int main() {
    ContactNode* head = new ContactNode();
    ContactNode* currContact = nullptr;
    ContactNode* endList = nullptr;
    string personName, personNumber;
    //cout << "got to this point" << endl;

    endList = head;


    for (int i = 0; i < 3; i++){
        cout << "Person " << i+1 << endl;
        cout << "Enter name: ";
        getline(cin, personName);
        cout << endl;
        cout << "Enter phone number: ";
        getline(cin, personNumber);
        cout << endl;
        cout << "You entered: " << personName << ", " << personNumber << endl << endl;


        currContact = new ContactNode(personName, personNumber);
        endList->InsertAfter(currContact);
        endList = currContact;
    }


    cout << "CONTACT LIST" << endl;
    currContact = head->GetNext();

    int loopCounter = 0;
    while (currContact != nullptr){
        currContact->PrintContactNode();
        currContact = currContact->GetNext();
        //cout << "finished loop " << loopCounter++ << endl;
    }
    //cout << "end of loop" << endl;
    return 0;
}
