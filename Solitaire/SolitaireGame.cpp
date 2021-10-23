//
// Created by Chase Ford on 6/13/20.
//
#pragma once
#include "SolitaireGame.h"

SolitaireGame::SolitaireGame() {
    //create a new deck of cards
    
    vector<Card*> myDeck;
    for(int i = 1; i <= 13; i++){
        Card* currSpadeCard = new Card(i, 'S');
        Card* currHeartCard = new Card(i, 'H');
        Card* currClubCard = new Card(i, 'C');
        Card* currDiamCard = new Card(i, 'D');

        myDeck.push_back(currSpadeCard);
        myDeck.push_back(currHeartCard);
        myDeck.push_back(currClubCard);
        myDeck.push_back(currDiamCard);
    }



    //create the solitaire stacks
    for(int i = 0; i < 7; i++){
        SolitaireStack* newStack = new SolitaireStack();
        playStacks.push_back(newStack);
    }
    //populate the solitaire stacks
    int randIndex;
    for (int i = 0; i < playStacks.size() && (!playStacks.empty()); i++){
        //We want the 0th stack to be populated by one card.
        // however, we want that stack to have 0 face down cards
        // and one face up card, adding one face down card each column.

        //adds i-1 face down cards to the ith column
        for (int j = 0; j < i; j++){
            randIndex = rand() % myDeck.size();
            playStacks.at(i)->AddFaceDownCard(myDeck.at(randIndex));
            myDeck.erase(myDeck.begin() + randIndex);
        }
        //adds a single face up card to the ith column
        randIndex = rand() % myDeck.size();
        playStacks.at(i)->AddFaceUpCard(myDeck.at(randIndex));
        myDeck.erase(myDeck.begin() + randIndex);

    }

    while(!myDeck.empty()){
        randIndex = rand() % myDeck.size();
        helpingCards.AddFaceDownCard(myDeck.at(randIndex));
        myDeck.erase(myDeck.begin() + randIndex);
        cout << "myDeck.size(): " << myDeck.size() << endl;
    }

    PrintMe();
}

void SolitaireGame::PrintMe() {
    cout << "play stacks:" << endl;
    for(int i = 0; i < playStacks.size(); i++){
        cout << i << ": " << flush << playStacks.at(i)->ToString() << endl;
    }

    cout << endl << "ace stacks:" << endl;
    for (int i = 0; i < aceStacks.size(); i++){
        cout << aceStacks.at(i)->GetLowFaceUpCard()->ToString() << " | ";
    }

    cout << endl << "help cards:" << endl;
    vector<Card*> topThree = helpingCards.GetAllFaceUpCards();
    int listSize = topThree.size();
    cout << helpingCards.GetFaceDownStackSize() << " | ";
    for (int i = listSize - 3; i < listSize; i++){
        if(i>=0){
            cout << topThree.at(i)->ToString() << " | ";
        }
    }


    cout << endl;
}

bool SolitaireGame::CheckWin() {
    bool win = true;
    if(aceStacks.empty()){
        win = false;
    }
    for (int i = 0; i < aceStacks.size(); i++){
        //if any of the top cards are not the kings,
        if(!(aceStacks.at(i)->GetLowFaceUpCard()->GetValue() == 13) ||
            (aceStacks.at(i)->GetLowFaceUpCard()->GetValue() == 13) ||
            (aceStacks.at(i)->GetLowFaceUpCard()->GetValue() == 13) ||
            (aceStacks.at(i)->GetLowFaceUpCard()->GetValue() == 13)){
            win = false;
        }
    }
    return win;
}

void SolitaireGame::FlipThreeHelpCards() {
    if(helpingCards.GetFaceDownStackSize() == 0){
        helpingCards.FlipOverHelpingStack();
    }
    helpingCards.FlipNextThree();
}

void SolitaireGame::MakeMove(int userChoice, int fromStack, int toStack) {
    const int TERMINATE_GAME = -1;
    const int MOVE_ENTIRE_STACK = 0;
    const int MOVE_ONE_CARD = 1;
    const int MOVE_HELPER_CARD = 2;
    const int MOVE_TO_ACE = 3;
    const int FLIP_NEXT_HELPERS = 4;

    if(userChoice == TERMINATE_GAME){
        cout << "Game terminated" << endl;
        return;
    }


    else if(userChoice == MOVE_ENTIRE_STACK){
        if(playStacks.at(fromStack)->GetFaceUpStackSize() == 0){
            cout << "Cannot move from empty stack." << endl;
            return;
        }
        Card* highFromCard = playStacks.at(fromStack)->GetHighFaceUpCard();
        if(highFromCard->GetValue() == 13){
            if(playStacks.at(toStack)->GetFaceDownStackSize() + playStacks.at(toStack)->GetFaceUpStackSize() == 0){
                vector<Card*> movingCards = playStacks.at(fromStack)->RemoveFaceUpStack();
                while(!movingCards.empty()){
                    playStacks.at(toStack)->AddFaceUpCard(movingCards.at(0));
                    movingCards.erase(movingCards.begin());
                }
                PrintMe();
            }else{
                cout << "That is not a valid move." << endl;
            }
            return;
        }

        Card* lowToCard = playStacks.at(toStack)->GetLowFaceUpCard();
        cout << "from value: " << highFromCard->GetValue() << endl << "to value: " << lowToCard->GetValue() << endl;
        cout << "from color " << highFromCard->GetColor() << endl << "to color: " << lowToCard->GetColor() << endl;
        if((lowToCard->GetValue() == highFromCard->GetValue() + 1) && (lowToCard->GetColor() != highFromCard->GetColor())){
            //valid move
            vector<Card*> movingCards = playStacks.at(fromStack)->RemoveFaceUpStack();
            while(!movingCards.empty()){
                playStacks.at(toStack)->AddFaceUpCard(movingCards.at(0));
                movingCards.erase(movingCards.begin());
            }

        }else {
            cout << "That is not a valid move" << endl;
            return;
        }
    }


    else if(userChoice == MOVE_ONE_CARD){
        if(playStacks.at(fromStack)->GetFaceUpStackSize() == 0){
            cout << "Cannot move from empty stack." << endl;
            return;
        }
        Card* movingCard = playStacks.at(fromStack)->GetLowFaceUpCard();

        if(movingCard->GetValue() == 13){
            if(playStacks.at(toStack)->GetFaceDownStackSize() + playStacks.at(toStack)->GetFaceUpStackSize() == 0){
                movingCard = playStacks.at(fromStack)->RemoveTopCard();
                playStacks.at(toStack)->AddFaceUpCard(movingCard);
                PrintMe();
            }else {
                cout << "That is not a valid move." << endl;
            }
            return;
        }

        if(playStacks.at(toStack)->GetFaceDownStackSize() + playStacks.at(toStack)->GetFaceUpStackSize() == 0) {
            Card *lowToCard = playStacks.at(toStack)->GetLowFaceUpCard();

            if ((lowToCard->GetValue() == movingCard->GetValue() + 1) &&
                (lowToCard->GetColor() != movingCard->GetColor())) {
                //valid move
                movingCard = playStacks.at(fromStack)->RemoveTopCard();
                playStacks.at(toStack)->AddFaceUpCard(movingCard);
            } else {
                cout << "That is not a valid move" << endl;
                return;
            }
        }else{
            cout << "You cannot place a non-king on an empty stack." << endl;
        }
    }


    else if(userChoice == MOVE_HELPER_CARD){
        if(helpingCards.GetAllFaceUpCards().empty()){
            cout << "Helping cards empty" << endl;
            return;
        }

        Card* movingCard = helpingCards.GetLowFaceUpCard();


        if(toStack == -1){
            cout << "value: " << movingCard->GetValue() << endl;
            //check to see if the card is an ace, if so, push it to the back of the ace stacks.
            if(movingCard->GetValue() == 1){
                //card is ace
                SolitaireStack* newAceStack = new SolitaireStack();
                movingCard = helpingCards.RemoveTopCard();
                newAceStack->AddFaceUpCard(movingCard);
                aceStacks.push_back(newAceStack);
                PrintMe();
                return;
            }

            for(int i = 0; i < aceStacks.size(); i++){
                //check to see if the ace stacks have the suit of the card yet
                Card* topAceCard = aceStacks.at(i)->GetLowFaceUpCard();
                if((topAceCard->GetSuit() == movingCard->GetSuit()) && (topAceCard->GetValue() == movingCard->GetValue() - 1)){
                    movingCard = helpingCards.RemoveTopCard();
                    aceStacks.at(i)->AddFaceUpCard(movingCard);
                }
            }
            PrintMe();
            return;
        }

        if(movingCard->GetValue() == 13){
            if(playStacks.at(toStack)->GetFaceUpStackSize() + playStacks.at(toStack)->GetFaceDownStackSize() == 0){
                //toStack is empty, king can move
                movingCard = helpingCards.RemoveTopCard();
                playStacks.at(toStack)->AddFaceUpCard(movingCard);
                PrintMe();
                return;
            }else {
                cout << "That is not a valid move" << endl;
                return;
            }
        }
        if(playStacks.at(toStack)->GetFaceUpStackSize() + playStacks.at(toStack)->GetFaceDownStackSize() != 0) {
            Card *lowToCard = playStacks.at(toStack)->GetLowFaceUpCard();

            if ((lowToCard->GetValue() == movingCard->GetValue() + 1) &&
                (lowToCard->GetColor() != movingCard->GetColor())) {
                //valid move
                movingCard = helpingCards.RemoveTopCard();
                playStacks.at(toStack)->AddFaceUpCard(movingCard);
            } else {
                cout << "That is not a valid move" << endl;
                return;
            }
        }else {
            cout << "You cannot place a non-king on an empty stack." << endl;
        }

    }


    else if(userChoice == MOVE_TO_ACE){
        if(playStacks.at(fromStack)->GetFaceUpStackSize() == 0){
            cout << "Cannot move from empty stack." << endl;
            return;
        }
        Card* movingCard = playStacks.at(fromStack)->GetLowFaceUpCard();
        if(movingCard->GetValue() == 1){
            //card is ace
            SolitaireStack* newAceStack = new SolitaireStack();
            movingCard = playStacks.at(fromStack)->RemoveTopCard();
            newAceStack->AddFaceUpCard(movingCard);
            aceStacks.push_back(newAceStack);
            PrintMe();
            return;
        }

        for(int i = 0; i < aceStacks.size(); i++){
            //check to see if the ace stacks have the suit of the card yet
            Card* topAceCard = aceStacks.at(i)->GetLowFaceUpCard();
            if((topAceCard->GetSuit() == movingCard->GetSuit()) && (topAceCard->GetValue() == movingCard->GetValue() - 1)){
                movingCard = playStacks.at(fromStack)->RemoveTopCard();
                aceStacks.at(i)->AddFaceUpCard(movingCard);
            }
        }
        PrintMe();
        return;
    }


    else if(userChoice == FLIP_NEXT_HELPERS){
        FlipThreeHelpCards();
    }
    PrintMe();
}

int SolitaireGame::GetNumberOfCardsInStack(int playStackNum) {
    return playStacks.at(playStackNum)->GetFaceDownStackSize() + playStacks.at(playStackNum)->GetFaceUpStackSize();
}

Card *SolitaireGame::GetLowFaceUpCard(int playStackNum) {
    return playStacks.at(playStackNum)->GetLowFaceUpCard();
}

Card *SolitaireGame::GetHighFaceUpCard(int playStackNum) {
    return playStacks.at(playStackNum)->GetHighFaceUpCard();
}

int SolitaireGame::GetAceStackSize() {
    return aceStacks.size();
}

Card *SolitaireGame::GetAceStackTopCard(int aceStackNum) {
    return aceStacks.at(aceStackNum)->GetLowFaceUpCard();
}

Card *SolitaireGame::GetHelperStackTopCard() {
    return helpingCards.GetLowFaceUpCard();
}

int SolitaireGame::GetNumberOfFaceDownCardsInStack(int playStackNum) {
    cout << "SolitaireGame::GetNumberOfFaceDownCardsInStack(" << playStackNum << ")" << endl;
    return playStacks.at(playStackNum)->GetFaceDownStackSize();
}
