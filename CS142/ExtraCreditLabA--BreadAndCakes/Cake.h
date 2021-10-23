//
// Created by Chase Ford on 9/26/20.
//

#ifndef EXTRACREDITLABA__BREADANDCAKES_CAKE_H
#define EXTRACREDITLABA__BREADANDCAKES_CAKE_H
#include "BakedGood.cpp"

class Cake : public BakedGood{
public:
    Cake();
    Cake(string flav, string frost);
    virtual double DiscountedPrice(int numberOfGoods) override = 0;
    virtual double PricePerItem() override = 0;

protected:
    string flavor;
    string frosting;
    const string CREAM_CHEESE = "cream-cheese";
};


#endif //EXTRACREDITLABA__BREADANDCAKES_CAKE_H
