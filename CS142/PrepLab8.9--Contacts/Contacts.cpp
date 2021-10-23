//
// Created by Chase Ford on 5/28/20.
//

#include "Contacts.h"

ContactNode::ContactNode() {
    contactName = "nobody";
    contactPhoneNumber = "000-000-0000";
    nextNodePtr = nullptr;
}

ContactNode::ContactNode(string name, string number){
    contactName = name;
    contactPhoneNumber = number;
    nextNodePtr = nullptr;
}

void ContactNode::InsertAfter(ContactNode* nextNode) {
    ContactNode* temporaryPointer = this->nextNodePtr;
    this->nextNodePtr = nextNode;
    nextNode->nextNodePtr = temporaryPointer;
}

string ContactNode::GetName() {
    return this->contactName;
}

string ContactNode::GetPhoneNumber() {
    return this->contactPhoneNumber;
}

ContactNode *ContactNode::GetNext() {
    return this->nextNodePtr;
}

void ContactNode::PrintContactNode() {
    cout << "Name: " << this->GetName() << endl;
    cout << "Phone number: " << this->GetPhoneNumber() << endl;
    cout << endl;
}
