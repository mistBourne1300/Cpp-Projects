//
// Created by Chase Ford on 6/12/20.
//
#pragma once
#include "SolitaireStack.h"

void SolitaireStack::AddFaceDownCard(Card *newCard) {
    faceDownStack.push_back(newCard);
}

void SolitaireStack::AddFaceUpCard(Card *newCard) {
    faceUpStack.push_back(newCard);
}

void SolitaireStack::RevealTopFaceDownCard() {
    if(!faceUpStack.empty()){
        return;
    }
    if(faceDownStack.empty()){
        return;
    }
    faceUpStack.push_back(faceDownStack.back());
    faceDownStack.pop_back();
}

Card* SolitaireStack::RemoveTopCard() {
    Card* oldTopCard = faceUpStack.back();
    faceUpStack.pop_back();
    if(faceUpStack.empty()){
        RevealTopFaceDownCard();
    }
    return oldTopCard;
}

vector<Card *> SolitaireStack::RemoveFaceUpStack() {
    vector<Card*> oldStack = faceUpStack;
    faceUpStack.clear();
    RevealTopFaceDownCard();
    return oldStack;
}

string SolitaireStack::ToString() {
    ostringstream outSS;

    for(int i = 0; i < faceDownStack.size(); i++){
        outSS << "??? | ";
    }
    for (int i = 0; i < faceUpStack.size(); i++){
        outSS << faceUpStack.at(i)->ToString();
        if(i != faceUpStack.size() - 1){
            outSS << " | ";
        }
    }
    return outSS.str();
}

Card *SolitaireStack::GetLowFaceUpCard() {
    return faceUpStack.back();
}

Card *SolitaireStack::GetHighFaceUpCard() {
    if(faceUpStack.empty()){
        return nullptr;
    }
    return faceUpStack.at(0);
}

vector<Card *> SolitaireStack::GetAllFaceUpCards() {
    return faceUpStack;
}


void SolitaireStack::FlipNextThree() {
    for(int i = 0;(i < 3) && !(faceDownStack.empty()); i++){
        faceUpStack.push_back(faceDownStack.back());
        faceDownStack.pop_back();
    }

}

void SolitaireStack::FlipOverHelpingStack() {
    while(!(faceUpStack.empty())){
        faceDownStack.push_back(faceUpStack.back());
        faceUpStack.pop_back();
    }
}

int SolitaireStack::GetFaceDownStackSize() {
    return faceDownStack.size();
}

int SolitaireStack::GetFaceUpStackSize() {
    return faceUpStack.size();
}
