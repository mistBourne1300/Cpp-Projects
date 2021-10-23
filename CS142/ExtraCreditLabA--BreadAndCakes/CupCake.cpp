//
// Created by Chase Ford on 9/26/20.
//

#include "CupCake.h"

CupCake::CupCake() {
    flavor = "NO_INIT";
    frosting = "NO_INIT";
    sprinklesColor = "NO_INIT";
    basePrice = 1.95;
}

CupCake::CupCake(string flav, string frost, string sprinkles) {
    flavor = flav;
    frosting = frost;
    sprinklesColor = sprinkles;
    basePrice = 1.95;
}

double CupCake::DiscountedPrice(int numberOfGoods) {
    double discountPerItem = 0.0;
    if(numberOfGoods >= 4){
        discountPerItem = .4;
    }else if(numberOfGoods >= 2){
        discountPerItem = .3;
    }
    double discountedPrice = numberOfGoods * (PricePerItem() - discountPerItem);
    return discountedPrice;
}

double CupCake::PricePerItem() {
    double price = basePrice;
    if(frosting == CREAM_CHEESE){
        price += PRICE_FOR_CREAM_CHEESE;
    }
    return price;
}

string CupCake::ToString() {
    ostringstream outSS;
    outSS << flavor << " cupcake with " << frosting << " frosting and "
            << sprinklesColor << " sprinkles " << Cake::ToString();
    return outSS.str();
}
