#include <iostream>
#include <vector>
#include <iomanip>
#include <ios>
#include <cmath>
using namespace std;

int main() {
    const double TOlERANCE = .0001;
    double currPrice = 0.0, salesTax = 0.0, subTotal = 0.0, total = 0.0;

    do{
        cin >> currPrice;
        subTotal += currPrice;
    }while(fabs(currPrice) > TOlERANCE);

    salesTax = subTotal * .07;
    total = subTotal + salesTax;
    cout << "subtotal: $" << fixed << setprecision(2) << subTotal << endl;
    cout << "sales tax: $" << fixed << setprecision(2) << salesTax << endl;
    cout << "total: $" << fixed << setprecision(2) << total << endl;
}
