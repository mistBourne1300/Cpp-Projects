//
// Created by Chase Ford on 5/21/20.
//

#ifndef ONLINESHOOPINGCART_SHOPPINGCART_H
#define ONLINESHOOPINGCART_SHOPPINGCART_H
#include <string>
#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
using namespace std;
#include "ItemToPurchase.h"


class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string GetCustomerName();
    string GetDateCreated();
    void AddItemToCart(const ItemToPurchase& newItem);
    void RemoveItemFromCart(const string& itemName);
    void UpdateItemQuantity(string itemName, int newQuantity);
    int GetQuantityOfItems();
    double GetTotalCostOfCart();
    void PrintItemDescriptions();
    void PrintItemsQuantityAndTotalCost();

private:
    string customerName;
    string dateCreated;
    vector<ItemToPurchase> cartItems;
};


#endif ONLINESHOOPINGCART_SHOPPINGCART_H
