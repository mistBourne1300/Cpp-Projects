//
// Created by Chase Ford on 9/26/20.
//

#ifndef EXTRACREDITLABA__BREADANDCAKES_CUPCAKE_H
#define EXTRACREDITLABA__BREADANDCAKES_CUPCAKE_H
#include "Cake.cpp"


class CupCake : public Cake{
public:
    CupCake();
    CupCake(string flav, string frost, string sprinkles);
    double DiscountedPrice(int numberOfGoods) override;
    double PricePerItem() override;
    string ToString() override;

protected:
    string sprinklesColor;
    const double PRICE_FOR_CREAM_CHEESE = .2;
};


#endif //EXTRACREDITLABA__BREADANDCAKES_CUPCAKE_H
