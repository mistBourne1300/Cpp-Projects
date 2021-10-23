//
// Created by Chase Ford on 6/8/20.
//

#ifndef THIS_IS_WAR_CARD_H
#define THIS_IS_WAR_CARD_H
#include <string>
#include <sstream>
using namespace std;


class Card {
public:
    explicit Card(int value = 0, char suit = 'N');

    int GetValue() const {return cardValue;}
    void SetValue(int value);

    char GetSuit() const {return cardSuit;}
    void SetSuit(char suit);

    char GetColor() const {return cardColor;}

    bool operator==(Card& rhs) const;
    bool operator<(Card& rhs) const;
    bool operator!=(Card& rhs) const;

    string ToString();


private:
    void SetColor();

    int cardValue;
    char cardSuit;
    char cardColor;


};


#endif //THIS_IS_WAR_CARD_H
