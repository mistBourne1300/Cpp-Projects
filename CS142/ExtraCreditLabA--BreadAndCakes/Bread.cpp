//
// Created by Chase Ford on 9/26/20.
//

#include "Bread.h"

Bread::Bread() {
    variety = "NO_INIT";
    basePrice = 4.5;
}

Bread::Bread(string desc) {
    variety = desc;
    basePrice = 4.5;
}

string Bread::ToString() {
    ostringstream outSS;
    outSS << variety << " bread " << BakedGood::ToString();
    return outSS.str();
}

double Bread::DiscountedPrice(int numberOfGoods) {
    int numberOfFreeBreads = numberOfGoods / 3;
    double discountedPrice = (numberOfGoods - numberOfFreeBreads) * PricePerItem();
    return discountedPrice;
}

double Bread::PricePerItem() {
    return basePrice;
}
