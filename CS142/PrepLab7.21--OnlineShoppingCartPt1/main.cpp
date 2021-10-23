#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;
#include "ItemToPurchase.h"

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;

    string currName;
    double currPrice;
    int currQuantity;
    double item1Tot;
    double item2Tot;

    cout << "Item 1" << endl;
    cout << "Enter the item name: ";
    getline(cin, currName);
    cout << "Enter the item price: ";
    cin >> currPrice;
    cin.ignore();
    cout << "Enter the item quantity: ";
    cin >> currQuantity;
    cin.ignore();
    cout << endl;

    item1.SetName(currName);
    item1.SetPrice(currPrice);
    item1.SetQuantity(currQuantity);
    item1Tot = item1.GetPrice() * item1.GetQuantity();

    cout << "Item 2" << endl;
    cout << "Enter the item name: ";
    getline(cin, currName);
    cout << "Enter the item price: ";
    cin >> currPrice;
    cin.ignore();
    cout << "Enter the item quantity: ";
    cin >> currQuantity;
    cin.ignore();
    cout << endl;

    item2.SetName(currName);
    item2.SetPrice(currPrice);
    item2.SetQuantity(currQuantity);
    item2Tot = item2.GetPrice() * item2.GetQuantity();


    cout << fixed << setprecision(2) << "TOTAL COST" << endl;
    cout << item1.GetName() << " "
         << item1.GetQuantity()
         << " @ $" << item1.GetPrice()
         << " = $" << item1Tot << endl;

    cout << fixed << setprecision(2) << item2.GetName() << " "
         << item2.GetQuantity()
         << " @ $" << item2.GetPrice()
         << " = $" << item2Tot << endl;
    cout << endl;
    cout << fixed << setprecision(2) << "Total: $" << (item1Tot + item2Tot) << endl;
}
