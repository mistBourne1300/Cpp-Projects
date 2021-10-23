//
// Created by Chase Ford on 6/8/20.
//

#include "Card.h"


Card::Card(int value, char suit) {
    if(value > 14){value = 14;}
    if(value < 2){value = 2;}
    cardValue = value;


    cardSuit = suit;


    if ((cardSuit == 'C') || (cardSuit == 'S')){
        cardColor = 'B';
    }else if ((cardSuit == 'H') || (cardSuit == 'D')){
        cardColor = 'R';
    }else {
        cardColor = 'N';
    }
}

void Card::SetValue(int value) {
    if(value > 14){value = 14;}
    if(value < 2){value = 2;}
    cardValue = value;
}

void Card::SetSuit(char suit) {
    cardSuit = suit;
}

void Card::SetColor() {
    if ((cardSuit == 'C') || (cardSuit == 'S')){
        cardColor = 'B';
    }else if ((cardSuit == 'H') || (cardSuit == 'D')){
        cardColor = 'R';
    }else {
        cardColor = 'N';
    }
}

bool Card::operator==(Card& rhs) const {
    return (this->GetValue() == rhs.GetValue());
}

bool Card::operator<(Card &rhs) const {
    return (this->GetValue() < rhs.GetValue());
}

bool Card::operator!=(Card &rhs) const {
    return this->GetValue() != rhs.GetValue();
}

string Card::ToString() {
    ostringstream outSS;
    if(cardValue < 11){
        outSS << cardValue << " of " << cardSuit;
    }else if(cardValue == 11){
        outSS << "J of " << cardSuit;
    }else if(cardValue == 12){
        outSS << "Q of " << cardSuit;
    }else if(cardValue == 13){
        outSS << "K of " << cardSuit;
    }else if(cardValue == 14){
        outSS << "A of " << cardSuit;
    }else{
        outSS << "Houston, we have a problem";
    }


    return outSS.str();
}