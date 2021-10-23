//
// Created by Chase Ford on 6/19/20.
//
// 3 6
// 0 6 5
// 0 1 6
// 0 1 6
#pragma once
#include "SolitairePlayer.h"

SolitairePlayer::SolitairePlayer() {
    currMovingCard = nullptr;
    lastCardMoved = nullptr;
    cardBeforeMoved = nullptr;
    currMovingCardPlayStackLoc = -1;
}

bool SolitairePlayer::GameOn() {
    //TODO:: add a check on making the same move multiple times (mostly for kings)
    bool canContinue = true;
    currMovingCard = nullptr;
    //continue the game while it is still possible to win
    while(canContinue && !gameOfThrones.CheckWin()){
        /*string throwAway;
        cout << "PRESS ENTER TO CONTINUE" << endl;
        getline(cin, throwAway);*/
        bool cardMoved = false;
        // go through each face up stacks and see if the highest card can move
        // to another play stack. If so, move it
        for(int i = 6; i >= 0; i--){

            currMovingCard = gameOfThrones.GetHighFaceUpCard(i);
            currMovingCardPlayStackLoc = i;

            //check if the current card can move, if so, move it;
            if(CanCurrCardMove()){

                int toStack = WhereCurrCardCanMove();
                // check where the current card can move
                if(toStack >= 0 && toStack < 7){
                    cout << "Move: 0 " << i << " " << toStack << endl;
                    MoveCard(0, i, toStack);
                    cardMoved = true;
                }
            }

        }

        // check whether a card was moved, if so, start the while loop over
        if(cardMoved){
            continue;
        }

        //go through the lowest face up cards and see if they can move to the ace stacks
        for(int i = 6; i >= 0; i--){
            currMovingCard = gameOfThrones.GetLowFaceUpCard(i);
            currMovingCardPlayStackLoc = i;
            if(CanCurrCardMove()){
                int toStack = WhereCurrCardCanMove();
                // check whether the card can move to the ace stacks
                if(toStack == -1){
                    cout << "Move: 3 " << i << endl;
                    MoveCard(3, i);
                    cardMoved = true;
                }
            }

        }

        // check whether a card was moved, if so, start the while loop over
        if(cardMoved){
            continue;
        }

        // go through the helping stack, flipping the top cards
        // (at most 20 flips)
        // and see if anything can move
        // if nothing moves, then we need to stop the game
        // TODO::make sure to add a break; statement or we're in trouble
        for (int i = 0; i < 20; i++){
            cout << "Move: 4" << endl;
            gameOfThrones.MakeMove(4);
            currMovingCard = gameOfThrones.GetHelperStackTopCard();
            if(CanCurrCardMove()){
                int toStack = WhereCurrCardCanMove();
                cout << "Move: 2 0 " << toStack << endl;
                MoveCard(2, 0, toStack);
                cardMoved = true;
                break;
            }
        }
        if(cardMoved){
            continue;
        }else{
            cout << "Looped through helper deck" << endl;
            canContinue = false;
        }
        //if the current card has moved twice in a row, quit the game
        cout << "Current Card: " << currMovingCard->ToString() << endl;
        cout << "Last Card: " << lastCardMoved->ToString() << endl;
        cout << "Card Before: " << cardBeforeMoved->ToString() << endl;
        if(currMovingCard->ToString() == lastCardMoved->ToString() && lastCardMoved->ToString() == cardBeforeMoved->ToString()){
            cout << "Card moved twice in a row" << endl;
            canContinue = false;
        }
    }

    return gameOfThrones.CheckWin();
}

bool SolitairePlayer::CanCurrCardMove() {
    cout << "SolitairePlayer::CanCurrCardMove()" << endl;

    Card* comparisonCard;
    if(currMovingCard == nullptr){
        return false;
    }
    //if card is ace, it can move to the ace stacks
    if(currMovingCard->GetValue() == 1){
        return true;
    }

    //check each ace stack and see if the curr card can move there
    for(int i = 0; i < gameOfThrones.GetAceStackSize(); i++){
        comparisonCard = gameOfThrones.GetAceStackTopCard(i);
        if((comparisonCard->GetValue() == currMovingCard->GetValue() - 1) &&
           (comparisonCard->GetSuit() == currMovingCard->GetSuit())){
            return true;
        }
    }

    //if the card is a King, check it's current stack's face down card size.
    // If it's 0, the card should not move.
    // otherwise, check if any stack is empty
    cout << "Here? currMovingCardPlayStackLoc = " << currMovingCardPlayStackLoc << endl;
    gameOfThrones.GetNumberOfFaceDownCardsInStack(currMovingCardPlayStackLoc);
    if(currMovingCard->GetValue() == 13 && (gameOfThrones.GetNumberOfFaceDownCardsInStack(currMovingCardPlayStackLoc) != 0)){
        for(int i = 0; i < 7; i++){
            if(gameOfThrones.GetNumberOfCardsInStack(i) == 0 &&
                gameOfThrones.GetNumberOfCardsInStack(currMovingCardPlayStackLoc) != 0){
                return true;
            }
        }
    }

    //go through each playStack and see if it can move onto that card
    for(int i = 6; i >= 0; i--){
        comparisonCard = gameOfThrones.GetLowFaceUpCard(i);
        if((comparisonCard->GetValue() == currMovingCard->GetValue() + 1) &&
            (comparisonCard->GetColor() != currMovingCard->GetColor())){
            return true;
        }
    }






    return false;
}

int SolitairePlayer::WhereCurrCardCanMove() {
    Card* comparisonCard;
    if(currMovingCard->GetValue() == 1){
        return -1;
    }

    for(int i = 0; i < gameOfThrones.GetAceStackSize(); i++){
        comparisonCard = gameOfThrones.GetAceStackTopCard(i);
        if((comparisonCard->GetValue() == currMovingCard->GetValue() - 1) &&
           (comparisonCard->GetSuit() == currMovingCard->GetSuit())){
            return -1;
        }
    }

    if(currMovingCard->GetValue() == 13){
        for(int i = 0; i < 7; i++){
            if(gameOfThrones.GetNumberOfCardsInStack(i) == 0){
                return i;
            }
        }
    }

    //go through each playStack and see if it can move onto that card

    for(int i = 6; i >= 0; i--){
        comparisonCard = gameOfThrones.GetLowFaceUpCard(i);
        if((comparisonCard->GetValue() == currMovingCard->GetValue() + 1) &&
           (comparisonCard->GetColor() != currMovingCard->GetColor())){
            return i;
        }
    }




    return -100;
}

void SolitairePlayer::MoveCard(int playerChoice, int fromStack, int toStack) {
    gameOfThrones.MakeMove(playerChoice, fromStack, toStack);
    cardBeforeMoved = lastCardMoved;
    lastCardMoved = currMovingCard;
}
