//
// Created by Chase Ford on 6/4/20.
//

#ifndef REALESTATELAB_EXTRACREDIT_RESIDENTIAL_H
#define REALESTATELAB_EXTRACREDIT_RESIDENTIAL_H
#include "Property.h"


class Residential: public Property {
public:
    explicit Residential(const string& rental = "no", double value = 0.0, const string& occupied = "no", const string& ID = "no_init");

    bool GetOccipied();
    void SetOccupied(const string& occupied);

    string ToString() override;

    string ComputeTaxes() override;

    double GetTaxValue() override;

private:
    bool isOccupied;

};


#endif //REALESTATELAB_EXTRACREDIT_RESIDENTIAL_H
