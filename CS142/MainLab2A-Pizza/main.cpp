#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int numGuests;
    int guestRemain;

    int numLargePizzas;      //feeds 7 people; price is $14.68;  dia = 20in
    int numMedPizzas;        //feeds 3 people; price is $11.48;  dia = 16in
    int numSmallPizzas;      //feeds 1 person; price is $7.28;   dia = 12in

    double largePizzaArea;
    double medPizzaArea;
    double smallPizzaArea;
    double totPizzaArea;
    double servingSize;

    int tipPerc;
    double priceBeforeTip;
    double tipAmount;
    double totPrice;

    const double PI = 3.14159265;

    const double   LARGE_PIZZA_PRICE = 14.68;
    const int      LARGE_PIZZA_DIA = 20;
    const int      LARGE_PIZZA_SERVES = 7;

    const double   MED_PIZZA_PRICE = 11.48;
    const int      MED_PIZZA_DIA = 16;
    const int      MED_PIZZA_SERVES = 3;

    const double   SMALL_PIZZA_PRICE = 7.28;
    const int      SMALL_PIZZA_DIA = 12;
    const int      SMALL_PIZZA_SERVES = 1;


    //get the number of guests...
    cout << "Please enter how many guests to order for: ";
    cin >> numGuests;
    cout << endl;


    //calculates the number of pizzas to order
    numLargePizzas = numGuests / LARGE_PIZZA_SERVES;
    guestRemain = numGuests % LARGE_PIZZA_SERVES;

    numMedPizzas = guestRemain / MED_PIZZA_SERVES;
    guestRemain = guestRemain % MED_PIZZA_SERVES;

    numSmallPizzas = guestRemain / SMALL_PIZZA_SERVES;

    //prints out the pizza numbers
    cout << numLargePizzas << " large pizzas, " << numMedPizzas << " medium pizzas, and "
         << numSmallPizzas << " small pizzas will be needed." << endl;
    cout << endl;



    //calculates the area of pizza ordered, along with the serving size (total area / guest number)
    largePizzaArea = pow((LARGE_PIZZA_DIA / 2), 2) * PI * numLargePizzas;
    medPizzaArea = pow((MED_PIZZA_DIA / 2), 2) * PI * numMedPizzas;
    smallPizzaArea = pow((SMALL_PIZZA_DIA / 2), 2) * PI * numSmallPizzas;
    totPizzaArea = largePizzaArea + medPizzaArea + smallPizzaArea;
    servingSize = totPizzaArea / numGuests;

    //outputs total area and serving size
    cout << "A total of " << totPizzaArea << " square inches of pizza will be ordered ("
         << servingSize << " per guest)." << endl;
    cout << endl;

    //gets the user's desired tip percentage
    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
    cin >> tipPerc;
    cout << endl;

    //calculates the total and tip, adds tham, then outputs the results
    priceBeforeTip = (numLargePizzas * LARGE_PIZZA_PRICE) + (numMedPizzas * MED_PIZZA_PRICE) + (numSmallPizzas * SMALL_PIZZA_PRICE);
    tipAmount = priceBeforeTip * (tipPerc / 100.0);
    totPrice = round(priceBeforeTip + tipAmount);
    cout << "The total cost of the event will be: $" << totPrice << endl;


}