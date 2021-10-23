#include <iostream>
#include <random>
#include <string>
#include <cmath>
using namespace std;

void GameB1(int& userMoney);
bool RollDice();

void GameB2(int& userMoney);
bool PullAce();

void GameA(int& userMoney);
bool PullRoyal();

int main() {
    srand(time(0));
    string pressEnter;
    std::cout << "Game B:" << std::endl;
    int userMonies = 100;
    for(int i = 0; i < 1000; i++){
        if(userMonies%3 != 0){
            GameB1(userMonies);
        }else{
            GameB2(userMonies);
        }
    }
    cout << "Final Net Worth (Game B): " << userMonies << endl;

    cout << "Game A:" << endl;
    userMonies = 100;
    for(int i = 0; i < 100; i++){
        GameA(userMonies);
    }
    cout << "Final Net Worth (Game A): " << userMonies << endl << endl;

    cout << "Now running optimization algorithm..." << endl << "Press Enter:" << endl;
    getline(cin, pressEnter);

    userMonies = 100;
    for(int i = 0; i < 10000; i++){
        cout << i;
        if(userMonies%3 != 0){
            GameB1(userMonies);
        }else{
            GameA(userMonies);
        }
    }
    cout << "Final New Worth (Game A & B): " << userMonies << endl;

    return 0;
}

bool RollDice(){
    cout << "\t" << "rolling dice..." << endl;
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    return die1 + die2 >= 7;
}

bool PullAce(){
    cout << "\t" << "pulling ace..." << endl;
    int picked = (rand() % 52) + 1;
    return picked > 48;
}

bool PullRoyal(){
    cout << "\t" << "pulling royal..." << endl;
    int picked = (rand() % 52) + 1;
    return picked > 36;
}

void GameA(int& userMoney){
    if(PullRoyal()){
        cout << "You gained 1 monies: " << ++userMoney << endl;
    }else{
        cout << "You lost 1 monies: " << --userMoney << endl;
    }
}

void GameB1(int& userMoney){
    if(userMoney % 3 != 0){
        if(RollDice()){
            cout << "You gained 1 monies: " << ++userMoney << endl;
        }else{
            cout << "You lost 1 monies: " << --userMoney << endl;
        }
    }else{
        cout << "You cannot play game B1" << endl;
    }
}

void GameB2(int& userMoney){
    if(userMoney % 3 == 0) {
        if (PullAce()) {
            cout << "You gained 1 monies: " << ++userMoney << endl;
        } else {
            cout << "You lost 1 monies: " << --userMoney << endl;
        }
    }else {
        cout << "You cannot play Game B2" << endl;
    }
}

