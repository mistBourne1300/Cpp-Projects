//
// Created by Chase Ford on 9/26/20.
//

#ifndef EXTRACREDITLABA__BREADANDCAKES_BREAD_H
#define EXTRACREDITLABA__BREADANDCAKES_BREAD_H
#include "BakedGood.cpp"


class Bread : public BakedGood {
public:
    Bread();
    explicit Bread(string desc);
    string ToString() override;
    double DiscountedPrice(int numberOfGoods) override;
    double PricePerItem() override;

protected:
    string variety;

};


#endif //EXTRACREDITLABA__BREADANDCAKES_BREAD_H
