//
// Created by Chase Ford on 6/4/20.
//

#include "Commercial.h"

Commercial::Commercial(const string& rental, double value, const string& deductible, double taxRate, const string& ID) {
    isRental = (rental == "yes");
    estValue = value;
    isDeductible = (deductible == "yes");
    taxDeducRate = taxRate;
    propID = ID;
}

bool Commercial::GetIsDeductible() {
    return isDeductible;
}

void Commercial::SetIsDeductible(const string& deductible) {
    isDeductible = (deductible == "yes");
}

double Commercial::GetTaxDeducRate() {
    return taxDeducRate;
}

void Commercial::SetTaxDeducRate(double rate) {
    taxDeducRate = rate;
}

string Commercial::ToString() {
    ostringstream outSS;

    outSS << "Address: " << propID << ". ";
    if(isRental){
        outSS << "Rental. ";
    }else{
        outSS << "NOT rental. ";
    }
    outSS << "Estimated value: " << fixed << setprecision(2) << setw(15) << estValue << ". ";
    outSS << "A Commercial Property. ";
    if(isDeductible){
        outSS << "In a discount zone with discount of: " << fixed << setprecision(2) << setw(15) << taxDeducRate << "%.";
    }else {
        outSS << "NOT in a discount zone.";
    }

    return outSS.str();
}

string Commercial::ComputeTaxes() {
    double taxValue;
    ostringstream outSS;

    if(isRental){
        taxValue = estValue * .012;
    }else {
        taxValue = estValue * .01;
    }
    if(isDeductible){
        taxValue = taxValue * (1 - (.01 * taxDeducRate) );
    }

    outSS << "** Taxes due for the property at: " << propID << endl;
    outSS << "  This property has an estimated value of:" << fixed << setw(15) << setprecision(2) << estValue << endl;
    outSS << "  Taxes due on this property are:" << fixed << setw(15) << setprecision(2) << taxValue << endl;

    return outSS.str();
}

double Commercial::GetTaxValue() {
    double taxValue;

    if(isRental){
        taxValue = estValue * .012;
    }else {
        taxValue = estValue * .01;
    }
    if(isDeductible){
        taxValue = taxValue * (1 - (.01 * taxDeducRate) );
    }

    return taxValue;
}
