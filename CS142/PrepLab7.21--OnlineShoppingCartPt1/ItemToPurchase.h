//
// Created by Chase Ford on 5/21/20.
//

#ifndef ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
#define ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
#include <string>
using namespace std;


class ItemToPurchase {
public:
    ItemToPurchase();
    void SetName(string name);
    string GetName();
    void SetPrice(double price);
    double GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();

private:
    string itemName;
    double itemPrice;
    int itemQuantity;
};


#endif //ONLINESHOPPINGCART_PT1_ITEMTOPURCHASE_H
