//
// Created by Chase Ford on 6/19/20.
//

#ifndef SOLITAIRE_SOLITAIREPLAYER_H
#define SOLITAIRE_SOLITAIREPLAYER_H
#include "SolitaireGame.cpp"


class SolitairePlayer {
public:
    SolitairePlayer();
    bool GameOn();
    bool CanCurrCardMove();
    int WhereCurrCardCanMove();
    void MoveCard(int playerChoice, int fromStack = 0, int toStack = 0);


private:
    SolitaireGame gameOfThrones;
    Card* currMovingCard;
    Card* lastCardMoved;
    Card* cardBeforeMoved;

    int currMovingCardPlayStackLoc;


};


#endif //SOLITAIRE_SOLITAIREPLAYER_H
