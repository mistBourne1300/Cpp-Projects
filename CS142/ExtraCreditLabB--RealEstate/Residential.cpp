//
// Created by Chase Ford on 6/4/20.
//

#include "Residential.h"

Residential::Residential(const string& rental, double value, const string& occupied, const string& ID) {
    isRental = (rental == "yes");
    estValue = value;
    isOccupied = (occupied == "yes");
    propID = ID;
}

bool Residential::GetOccipied() {
    return isOccupied;
}

void Residential::SetOccupied(const string& occupied) {
    isOccupied = (occupied == "yes");
}

string Residential::ToString() {
    ostringstream outSS;

    outSS <<  "Address: " << propID << ". ";
    if(isRental){
        outSS << "Rental. ";
    }else {
        outSS <<  "NOT rental. ";
    }
    outSS << "Estimated value: " << fixed << setw(15) << setprecision(2) << estValue << ". ";
    outSS << "A Residential Property. ";
    if(isOccupied){
        outSS << "Occupied.";
    }else {
        outSS << "NOT occupied.";
    }

    return outSS.str();

}

string Residential::ComputeTaxes() {
    double taxValue;
    ostringstream outSS;

    if(isOccupied){
        taxValue = estValue * .006;
    }else {
        taxValue = estValue * .009;
    }

    outSS << "** Taxes due for the property at: " << propID << endl;
    outSS << "  This property has an estimated value of:" << fixed << setw(15) << setprecision(2) << estValue << endl;
    outSS << "  Taxes due on this property are:" << fixed << setw(15) << setprecision(2) << taxValue << endl;

    return outSS.str();
}

double Residential::GetTaxValue() {
    double taxValue;

    if(isOccupied){
        taxValue = estValue * .006;
    }else {
        taxValue = estValue * .009;
    }

    return taxValue;
}
