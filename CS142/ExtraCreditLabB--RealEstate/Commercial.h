//
// Created by Chase Ford on 6/4/20.
//

#ifndef REALESTATELAB_EXTRACREDIT_COMMERCIAL_H
#define REALESTATELAB_EXTRACREDIT_COMMERCIAL_H
#include "Property.h"


class Commercial: public Property {
public:
    explicit Commercial(const string& rental = "no", double value = 0.0, const string& deductible = "no", double taxRate = 0.0, const string& ID = "no_init");

    bool GetIsDeductible();
    void SetIsDeductible(const string& deductible);

    double GetTaxDeducRate();
    void SetTaxDeducRate(double rate);

    string ToString() override;

    string ComputeTaxes() override;

    double GetTaxValue() override;

private:
    bool isDeductible;
    double taxDeducRate;
};


#endif //REALESTATELAB_EXTRACREDIT_COMMERCIAL_H
