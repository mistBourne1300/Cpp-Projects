//
// Created by Chase Ford on 5/21/20.
//

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    dateCreated = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    dateCreated = date;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDateCreated() {
    return dateCreated;
}

void ShoppingCart::AddItemToCart(const ItemToPurchase& newItem) {
    unsigned int i;
    for (i = 0; i <cartItems.size(); i++){
        if(newItem == cartItems.at(i)){
            cout << "Item is already found in the cart. It will not be added." << endl << endl;
            return;
        }
    }
    cartItems.push_back(newItem);
}

void ShoppingCart::RemoveItemFromCart(const string& itemName) {
    unsigned int i;
    for (i = 0; i < cartItems.size(); i++){
        if (itemName == cartItems.at(i).GetName()){
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. It will not be removed." << endl << endl;
}

void ShoppingCart::UpdateItemQuantity(string itemName, int newQuantity) {
    unsigned int i;
    for (i = 0; i < cartItems.size(); i++){
        if (itemName == cartItems.at(i).GetName()){
            cartItems.at(i).SetQuantity(newQuantity);
            return;
        }
    }
    cout << "Item not found in cart. It will not be modified." << endl << endl;
}

int ShoppingCart::GetQuantityOfItems() {
    return cartItems.size();
}

double ShoppingCart::GetTotalCostOfCart() {
    if (cartItems.size() == 0){
        return 0.0;
    }
    double totalCost = 0.0;
    unsigned int i;
    for (i = 0; i < cartItems.size(); i++){
        totalCost += cartItems.at(i).GetTotalPrice();
    }
    return totalCost;

}

void ShoppingCart::PrintItemDescriptions() {
    cout << customerName << "'s Shopping Cart - " << dateCreated << endl;
    if (cartItems.size() == 0){
        cout << "Shopping cart is empty." << endl << endl;
        return;
    }


    unsigned int i;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (i = 0; i < cartItems.size(); i++){
        cartItems.at(i).PrintDescription();
    }
    cout  << endl;
}

void ShoppingCart::PrintItemsQuantityAndTotalCost() {
    cout << customerName << "'s Shopping Cart - " << dateCreated << endl;
    if (cartItems.size() == 0){
        cout << "Shopping cart is empty." << endl << endl;
        return;
    }
    unsigned int i;
    int numberOfItems = 0;
    for (i = 0; i <cartItems.size(); i++){
        numberOfItems += cartItems.at(i).GetQuantity();
    }
    cout << "Number of Items: " << numberOfItems << endl << endl;
    for (i = 0; i < cartItems.size(); i++){
        cartItems.at(i).PrintCost();
    }
    cout << endl;
    cout << fixed << setprecision(2) << "Total: $" << GetTotalCostOfCart() << endl << endl;
}








