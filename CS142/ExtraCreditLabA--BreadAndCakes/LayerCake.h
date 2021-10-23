//
// Created by Chase Ford on 9/26/20.
//

#ifndef EXTRACREDITLABA__BREADANDCAKES_LAYERCAKE_H
#define EXTRACREDITLABA__BREADANDCAKES_LAYERCAKE_H
#include "Cake.cpp"

class LayerCake : public Cake{
public:
    LayerCake();
    LayerCake(string flav, string frost, int layers);
    double DiscountedPrice(int numberOfGoods) override;
    double PricePerItem() override;
    string ToString() override;

protected:
    int numLayers;
    const double EXTRA_COST_PER_LAYER = 3.0;
    const double DISCOUNT_PER_CAKE = 2.0;
    const double EXTRA_COST_PER_CREAM_CHEESE = 1.0;
};


#endif //EXTRACREDITLABA__BREADANDCAKES_LAYERCAKE_H
