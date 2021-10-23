//
// Created by Chase Ford on 6/12/20.
//

#pragma once

#include "Card.h"

Card::Card(int value, char suit) {
    if(value < 1){value = 1;}
    else if (value > 13){value = 13;}
    cardValue = value;
    cardSuit = suit;
    if((cardSuit == 'S') || (cardSuit == 'C')){
        cardColor = 'B';
    }else if((cardSuit == 'H') || (cardSuit == 'D')){
        cardColor = 'R';
    }else{
        cardColor = 'N';
    }

}

int Card::GetValue() const {
    cout << "Card::GetValue(): " << cardValue << endl;
    return cardValue;
}

char Card::GetSuit() const {
    return cardSuit;
}

char Card::GetColor() const {
    return cardColor;
}

string Card::ToString() const {
    ostringstream outSS;

    if (cardValue == 11){
        outSS << "J of " << cardSuit;
    } else if (cardValue == 12){
        outSS << "Q of " << cardSuit;
    } else if (cardValue == 13){
        outSS << "K of " << cardSuit;
    }else if (cardValue == 1){
        outSS << "A of " << cardSuit;
    }else {
        outSS << cardValue << " of " << cardSuit;
    }

    return outSS.str();
}
