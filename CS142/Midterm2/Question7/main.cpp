#include <iostream>
#include <vector>
using namespace std;

class Stock {
private:
    string tickerSymbol;
    vector<double> prices;
public:
    Stock(string givenTickerSymbol);
    double CalculateMovingAverage(int numberOfDays);
    void AddDataPoint(double price);
    void Report();
};

// Constructor
Stock::Stock(string givenTickerSymbol){
    tickerSymbol = givenTickerSymbol;
}
// (The constructor is declared on line 10 above, but that declaration
// doesn't include any code. Your job is to write the full function
// definition.)

// Calculate the moving average of the stock over a given numberOfDays
double Stock::CalculateMovingAverage(int numberOfDays) {
    double sum = 0;
    for (int i=prices.size()-numberOfDays; i<prices.size(); i++) {
        sum += prices.at(i);
    }
    return sum/numberOfDays;
}

// Add a new price point to the prices vector
void Stock::AddDataPoint(double price) {
    this->prices.push_back(price);
}

// This function reports on the stock's statistical properties
void Stock::Report() {
    cout << tickerSymbol << endl;
    cout << "Seven Day Moving Average: " << this->CalculateMovingAverage(7) << endl;
}

int main() {

    // Create a Stock object using the ticker symbol provided by the user
    string tickerSymbol;
    cin >> tickerSymbol;
    Stock myStock(tickerSymbol);

    // Load the most recent data into the Stock object
    double price;
    cin >> price;
    while (price != 0.0) {
        myStock.AddDataPoint(price);
        cin >> price;
    }

    // Calculate and show the stock's 7 day moving average
    myStock.Report();

    // Add a new data point
    double newPrice;
    cin >> newPrice;
    myStock.AddDataPoint(newPrice);

    // Recalculate the moving average and display stock info again
    myStock.Report();

    return 0;
}