//
// Created by Chase Ford on 6/12/20.
//

#ifndef SOLITAIRE_SOLITAIRESTACK_H
#define SOLITAIRE_SOLITAIRESTACK_H
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "Card.cpp"


class SolitaireStack {
public:
    void AddFaceDownCard(Card* newCard);
    void AddFaceUpCard(Card* newCard);

    void RevealTopFaceDownCard();

    Card* RemoveTopCard();
    vector<Card*> RemoveFaceUpStack();

    Card* GetLowFaceUpCard();
    Card* GetHighFaceUpCard();

    vector<Card*> GetAllFaceUpCards();

    string ToString();

    int GetFaceDownStackSize();
    int GetFaceUpStackSize();

    //these methods are for use in the helping cards stack only
    void FlipNextThree();
    void FlipOverHelpingStack();




private:
    vector<Card*> faceDownStack;
    vector<Card*> faceUpStack;

};


#endif //SOLITAIRE_SOLITAIRESTACK_H
