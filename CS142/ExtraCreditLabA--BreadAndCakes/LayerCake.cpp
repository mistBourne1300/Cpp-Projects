//
// Created by Chase Ford on 9/26/20.
//

#include "LayerCake.h"

LayerCake::LayerCake() {
    flavor = "NO_INIT";
    frosting = "NO_INIT";
    numLayers = 0;
    basePrice = 9.0;
}

LayerCake::LayerCake(string flav, string frost, int layers) {
    flavor = flav;
    frosting = frost;
    numLayers = layers;
    basePrice = 9.0;
}

double LayerCake::DiscountedPrice(int numberOfGoods) {
    double discountPerCake = 0;
    double discountedPrice = 0;
    if(numberOfGoods >= 3){
        discountPerCake = DISCOUNT_PER_CAKE;
    }
    discountedPrice = numberOfGoods * (PricePerItem() - discountPerCake);
    return discountedPrice;
}

double LayerCake::PricePerItem() {
    double price = basePrice;
    price += (numLayers -1) * EXTRA_COST_PER_LAYER;
    if(frosting == CREAM_CHEESE){
        price += numLayers * EXTRA_COST_PER_CREAM_CHEESE;
    }
    return price;
}

string LayerCake::ToString() {
    ostringstream outSS;
    outSS << numLayers << "-layer " << flavor << " cake with " << frosting << " frosting " << Cake::ToString();
    return outSS.str();
}

