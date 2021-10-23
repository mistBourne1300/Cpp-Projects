//
// Created by Chase Ford on 6/13/20.
//

#ifndef SOLITAIRE_SOLITAIREGAME_H
#define SOLITAIRE_SOLITAIREGAME_H
#include <cmath>
#include <iostream>
using namespace std;
#include "SolitaireStack.cpp"



class SolitaireGame {
public:
    SolitaireGame();
    void MakeMove(int userChoice = 0, int fromStack = 0, int toStack = 0);
    void PrintMe();
    bool CheckWin();

    void FlipThreeHelpCards();

    int GetNumberOfCardsInStack(int playStackNum);
    int GetNumberOfFaceDownCardsInStack(int playStackNum);

    Card* GetLowFaceUpCard(int playStackNum);
    Card* GetHighFaceUpCard(int playStackNum);

    int GetAceStackSize();
    Card* GetAceStackTopCard(int aceStackNum);

    Card* GetHelperStackTopCard();


private:
    vector<SolitaireStack*> playStacks;
    vector<SolitaireStack*> aceStacks;// only add cards to the face up piles
    SolitaireStack helpingCards;

};


#endif //SOLITAIRE_SOLITAIREGAME_H
