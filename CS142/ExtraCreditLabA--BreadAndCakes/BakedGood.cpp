//
// Created by Chase Ford on 9/26/20.
//

#include "BakedGood.h"

string BakedGood::ToString() {
    ostringstream outSS;
    outSS << "($" << fixed << setprecision(6) << PricePerItem() << ")";
    return outSS.str();
}

double BakedGood::DiscountedPrice(int numberOfGoods) {
    return numberOfGoods * basePrice;
}
