//
// Created by Chase Ford on 6/4/20.
//

#ifndef REALESTATELAB_EXTRACREDIT_PROPERTY_H
#define REALESTATELAB_EXTRACREDIT_PROPERTY_H
#include <string>
#include <ios>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;


class Property {
public:
    Property(const string& rental = "no", double value = 0.0, const string& ID = "no_init");
    virtual string ToString() = 0;



    bool GetRental();
    void SetRental(const string& rental);

    double GetValue();
    void SetValue(double value);

    string GetID();
    void SetID(string ID);

    virtual string ComputeTaxes() = 0;

    virtual double GetTaxValue() = 0;

protected:
    bool isRental;
    double estValue;
    string propID;

};


#endif //REALESTATELAB_EXTRACREDIT_PROPERTY_H
