//
// Created by Chase Ford on 5/21/20.
//

#ifndef ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
#define ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;


class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, double price, int quantity, string description);
    void SetName(string name);
    string GetName() const;
    void SetPrice(double price);
    double GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;
    void SetItemDescription(string description);
    string GetItemDescription() const;
    void PrintCost();
    void PrintDescription();
    double GetTotalPrice() const;


private:
    string itemName;
    double itemPrice;
    int itemQuantity;
    string itemDescription;
};

bool operator==(const ItemToPurchase& lhs, const ItemToPurchase& rhs);

#endif //ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
