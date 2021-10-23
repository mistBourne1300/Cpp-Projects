//
// Created by Chase Ford on 6/12/20.
//

#ifndef SOLITAIRE_CARD_H
#define SOLITAIRE_CARD_H
#include <string>
#include <sstream>
using namespace std;


class Card {
public:
    explicit Card(int value = 1, char suit = 'N');

    int GetValue() const;
    char GetSuit() const;
    char GetColor() const;

    string ToString() const;

private:
    int cardValue;
    char cardSuit;
    char cardColor;

};


#endif //SOLITAIRE_CARD_H
