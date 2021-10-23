#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#include "Card.cpp"
#include "SolitaireStack.cpp"
#include "SolitaireGame.cpp"
#include "SolitairePlayer.cpp"

int main() {


    SolitaireGame myGame;

    int userChoice;
    int fromStack;
    int toStack;
    /*do {
        cout << "Menu:" << endl;
        cout << "-1: Quit game" << endl;
        cout << "0: move an entire stack of cards" << endl;
        cout << "1: move just one (lowest) card" << endl;
        cout << "2: move the top helper card" << endl;
        cout << "3: move a just one (lowest) card to the ace stacks" << endl;
        cout << "4: Flip next helper cards" << endl;
        cout << "Please Enter your choice:";
        cin >> userChoice;
        cout << endl;
        while ((userChoice < -1) || (userChoice > 4)) {
            cout << "Please enter a valid option: ";
            cin >> userChoice;
            cout << endl;
        }

        fromStack = -100;
        toStack = -100;


        if (userChoice == 0) {
            //move an entire stack from one to the other
            while((fromStack < 0) || (fromStack > 7)){
                cout << "Enter a stack you would like to move FROM: ";
                cin >> fromStack;
                cout << endl;
            }
            while((toStack < 0) || (toStack > 7)){
                cout << "Enter the stack you would like to move TO: ";
                cin >> toStack;
                cout << endl;
            }

        }




        else if(userChoice == 1){
            //move the lowest card to a different stack
            while((fromStack < 0) || (fromStack > 7)){
                cout << "Enter a stack you would like to move FROM: ";
                cin >> fromStack;
                cout << endl;
            }
            while((toStack < 0) || (toStack > 7)){
                cout << "Enter the stack you would like to move TO: ";
                cin >> toStack;
                cout << endl;
            }
        }


        else if (userChoice == 2){
            //move the top helper card
            while((toStack < -1) || (toStack > 7)){
                cout << "Enter the stack you would like to move TO (-1 to move to the ace stacks) ";
                cin >> toStack;
                cout << endl;
            }
        }


        else if(userChoice == 3){
            while((fromStack < 0) || (fromStack > 7)){
                cout << "Enter a stack you would like to move FROM: ";
                cin >> fromStack;
                cout << endl;
            }
        }


        myGame.MakeMove(userChoice, fromStack, toStack);
    }while(userChoice != -1);*/


    if(!myGame.CheckWin()){
        cout << "Sorry, you lost." << endl;
    }else {
        cout << "Congratulations! You won!" << endl;
    }
    cout << endl << endl << endl;

    for (int i = 0; i < 100; i++){cout << "*";}
    cout << endl << "Now the computer will play the game" << endl;
    for (int i = 0; i < 100; i++){cout << "*";}
    
    string temp;
    cout << "\nPress Enter:" << endl;
    getline(cin, temp);
    cout << endl;

    SolitairePlayer compPlayer;
    if(compPlayer.GameOn()){
        cout << "The computer won" << endl;
    }else {
        cout << "The computer lost" << endl;
    }
    vector<bool> winStreak;
    for(int i = 0; i < 100; i++){
        srand(i);
        SolitairePlayer newPlayer;
        cout << "Computer no. " << i << endl;
        winStreak.push_back(newPlayer.GameOn());
    }
    for(int i = 0; i < winStreak.size(); i++){
        cout << i << ": " << winStreak.at(i) << endl;
    }

    return 0;
}
