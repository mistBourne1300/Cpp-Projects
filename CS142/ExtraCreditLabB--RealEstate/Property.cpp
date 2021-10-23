//
// Created by Chase Ford on 6/4/20.
//

#include "Property.h"

Property::Property(const string& rental, double value, const string& ID) {
    isRental = (rental == "yes");
    estValue = value;
    propID = ID;
}

bool Property::GetRental() {
    return isRental;
}

void Property::SetRental(const string& rental) {
    isRental = (rental == "yes");
}

double Property::GetValue() {
    return estValue;
}

void Property::SetValue(double value) {
    estValue = value;
}

string Property::GetID() {
    return propID;
}

void Property::SetID(string ID) {
    propID = ID;
}
