#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ios>
#include <iomanip>
#include <random>
using namespace std;
#include "Card.h"

double ComputeAverageValue(vector<Card*>& myDeck);

int main() {
    srand(time(0));
    vector<Card*> cardDeck;
    vector<Card*> player1;
    vector<Card*> player2;

    //unusual for loop structure to improve readability. cards range from 2-14(ace)
    for (int i = 2; i <= 14; i++){

        Card* currSpadeCard = new Card(i, 'S');
        Card* currHeartCard = new Card(i, 'H');
        Card* currClubCard = new Card(i, 'C');
        Card* currDiamondCard = new Card(i, 'D');

        cardDeck.push_back(currSpadeCard);
        cardDeck.push_back(currHeartCard);
        cardDeck.push_back(currClubCard);
        cardDeck.push_back(currDiamondCard);
    }

    cout << "Our Deck:" << endl;
    for(Card* card : cardDeck){
        cout << card->ToString() << endl;
    }
    cout << endl;

    //shuffle by randomly assigning each card pointer to a player vector
    while(!cardDeck.empty()){
        int randCardIndex = rand() % cardDeck.size();
        player1.push_back(cardDeck.at(randCardIndex));
        cardDeck.erase(cardDeck.begin() + randCardIndex);

        randCardIndex = rand() % cardDeck.size();
        player2.push_back(cardDeck.at(randCardIndex));
        cardDeck.erase(cardDeck.begin() + randCardIndex);
    }

    cout << "Player 1's Deck:" << endl;
    for (Card* card : player1){
        cout << card->ToString() << endl;
    }
    cout << endl << endl;

    cout << "Player 2's Deck:" << endl;
    for (Card* card : player2){
        cout << card->ToString() << endl;
    }
    cout << endl << endl;

    cout << "Player 1's Deck Average: " << ComputeAverageValue(player1) << endl;
    cout << "Player 2's Deck Average: " << ComputeAverageValue(player2) << endl;

    cout << endl << "FIGHT!" << endl;
    cout << "*************************************************************" << endl;
    cout << setw(15) << "player 1" << setw(10) << " | " << setw(15) << "player 2" << endl;

    //FIXME: fix the state where one player has only one card in their stack...
    // figure out: what should the logic be?
    int counter = 0;
    while ((!player1.empty()) && (!player2.empty())){
        counter++;
        cout << setw(15) << player1.at(0)->ToString() << setw(10) << " vs. " << setw(15) << player2.at(0)->ToString();
        if (player1.at(0)->GetValue() == player2.at(0)->GetValue()){
            string tempString;
            cout << endl << "We have War!" << endl;


            cout << "Player 1 has " << player1.size() << " cards."<< endl;
            cout << "Player 2 has " << player2.size() << " cards." << endl;

            cout << "Press enter to continue:";
            //getline(cin, tempString);
            cout << endl;


            //temporary placeholder for the betting cards
            vector<Card *> holdingQueue;
            bool allowPlayerAccess = true;

            if(player1.size() == 1){
                //player 1 forfeits because of lack of funds
                player2.push_back(player1.at(0));
                player1.erase(player1.begin());
                allowPlayerAccess = false;
            }else if(player2.size() == 1){
                //player 2 forfeits because of lack of funds
                player1.push_back(player2.at(0));
                player2.erase(player2.begin());
                allowPlayerAccess = false;
            }else{
                //both players have more than one card
                do{
                    //cout << "\t\tDEBUG 1" << endl;
                    // add player1's card to the holding queue
                    holdingQueue.push_back(player1.at(0));
                    player1.erase(player1.begin());
                    //cout << "\t\tDEBUG 2" << endl;
                    //add player 2's card to the holding queue
                    holdingQueue.push_back(player2.at(0));
                    player2.erase(player2.begin());

                    unsigned int i = 0;
                    //add cards to the holding queue. 3 max, if a player has less than four,
                    //then only add what they can give
                    while((i < 3) && (player1.size() > 1) && (player2.size() > 1)){
                        i++;
                        //cout << "DEBUG 3: counter: " << i << endl;
                        // add player1's card to the holding queue
                        holdingQueue.push_back(player1.at(0));
                        player1.erase(player1.begin());
                        //add player 2's card to the holding queue
                        //cout << "DEBUG 4: counter: " << i << endl;
                        holdingQueue.push_back(player2.at(0));
                        player2.erase(player2.begin());
                    }


                    //terminates when someone wins
                    //cout << "DEBUG 5" << endl;
                }while(*player1.at(0) == *player2.at(0));
                if(allowPlayerAccess){
                    cout << setw(15) << player1.at(0)->ToString() << setw(10) << " vs. " << setw(15) << player2.at(0)->ToString() << endl;
                }

                if(*player1.at(0) < *player2.at(0)){
                    //add the final cards to player 2's hand
                    //cout << "player 2 takes " << player1.at(0)->ToString() << endl;
                    holdingQueue.push_back(player1.at(0));
                    player1.erase(player1.begin());
                    //move player 2's card to the back
                    player2.push_back(player2.at(0));
                    player2.erase(player2.begin());
                    //player 2 takes the stash
                    while(!holdingQueue.empty()) {
                        cout << "player 2 takes " << holdingQueue.at(0)->ToString() << endl;
                        player2.push_back(holdingQueue.at(0));
                        holdingQueue.erase(holdingQueue.begin());
                    }
                }else if(*player2.at(0) < *player1.at(0)){
                    //add the final card to holding queue
                    //cout << "player 1 takes " << player2.at(0)->ToString() << endl;
                    holdingQueue.push_back(player2.at(0));
                    player2.erase(player2.begin());
                    //move player 1's card to the back
                    player1.push_back(player1.at(0));
                    player1.erase(player1.begin());
                    //player 1 takes the stash
                    while(!holdingQueue.empty()) {
                        cout << "player 1 takes " << holdingQueue.at(0)->ToString() << endl;
                        player1.push_back(holdingQueue.at(0));
                        holdingQueue.erase(holdingQueue.begin());
                    }
                }else {
                    cout << "houston, we have a problem..." << endl;
                    return -1;
                }

            }
        }else if(*player1.at(0) < *player2.at(0)){
            cout << setw(20) << "player 2 takes: " << player1.at(0)->ToString() << endl;

            //give player 1's card to player 2
            player2.push_back(player1.at(0));
            player1.erase(player1.begin());

            //move player 2's card to the back
            player2.push_back(player2.at(0));
            player2.erase(player2.begin());


        }else {
            cout << setw(20) << "player 1 takes: " << player2.at(0)->ToString() << endl;
            //give player 2's card to player 1
            player1.push_back(player2.at(0));
            player2.erase(player2.begin());

            //move player 1's card to the back
            player1.push_back(player1.at(0));
            player1.erase(player1.begin());
        }
    }
    cout << "DONE" << endl;
    if(player1.empty()){
        cout << "player 2 wins:" << endl;
        /*for (Card* card : player2){
            cout << card->ToString() << endl;
        }*/
    }else {
        cout << "player 1 wins:" << endl;
        /*for (Card* card : player1){
            cout << card->ToString() << endl;
        }*/
    }

    cout << "It took " << counter << " battles to finish the game." << endl;


    return 0;
}


double ComputeAverageValue(vector<Card*>& myDeck){
    int deckSum = 0;
    double deckAvg;
    for (Card* card : myDeck){
        deckSum += card->GetValue();
    }
    deckAvg = static_cast<double>(deckSum) / myDeck.size();
    return deckAvg;
}