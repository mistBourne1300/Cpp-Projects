//
// Created by Chase Ford on 5/21/20.
//

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, double price, int quantity, string description) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

string ItemToPurchase::GetName() const{
    return itemName;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

double ItemToPurchase::GetPrice()  const{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const{
    return itemQuantity;
}

void ItemToPurchase::SetItemDescription(string description) {
    itemDescription = description;
}

string ItemToPurchase::GetItemDescription() const{
    return itemDescription;
}

void ItemToPurchase::PrintCost() {
    cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << GetTotalPrice() << endl;
}

void ItemToPurchase::PrintDescription() {
    cout << itemName << ": " << itemDescription << endl;
}

double ItemToPurchase::GetTotalPrice() const {
    return itemPrice * itemQuantity;
}

bool operator==(const ItemToPurchase& lhs, const ItemToPurchase& rhs){
    return lhs.GetName() == rhs.GetName();
}
