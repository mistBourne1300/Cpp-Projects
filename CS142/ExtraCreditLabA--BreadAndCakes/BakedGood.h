//
// Created by Chase Ford on 9/26/20.
//

#ifndef EXTRACREDITLABA__BREADANDCAKES_BAKEDGOOD_H
#define EXTRACREDITLABA__BREADANDCAKES_BAKEDGOOD_H
#include <string>
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
using namespace std;

class BakedGood {
public:
    virtual string ToString();
    virtual double DiscountedPrice(int numberOfGoods) = 0;
    virtual double PricePerItem() = 0;

protected:
    double basePrice;
};


#endif //EXTRACREDITLABA__BREADANDCAKES_BAKEDGOOD_H
