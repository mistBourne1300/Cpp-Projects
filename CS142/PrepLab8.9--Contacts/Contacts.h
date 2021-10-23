//
// Created by Chase Ford on 5/28/20.
//

#ifndef CONTACTS_LISTNODES__CONTACTS_H
#define CONTACTS_LISTNODES__CONTACTS_H
#include <string>
#include <iostream>
using namespace std;

class ContactNode{
public:
    ContactNode();
    ContactNode(string name, string number);
    void InsertAfter(ContactNode* nextNode);
    string GetName();
    string GetPhoneNumber();
    ContactNode* GetNext();
    void PrintContactNode();

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode* nextNodePtr;

};


#endif //CONTACTS_LISTNODES__CONTACTS_H
