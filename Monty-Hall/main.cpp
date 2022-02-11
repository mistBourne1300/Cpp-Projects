#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <random>
#include <string>
using namespace std;

void PopulateDoors(vector<bool>& doors, int numDoors);

int DoorToNotReveal(vector<bool>& doors, int userGuess);

void PrintDoors(vector<bool>& doors, int userGuess, int hiddenDoor);

bool DoesUserWin(const vector<bool>& doors, int userGuess);

double FindPercentage(const string fileName);

int main() {
    srand(time(0));
    int userGuess;
    int numDoors;
    int hiddenDoor;

    char doesUserSwitch;
    vector<bool> doors;




    cout << "Enter the number of doors you would like to play with: ";
    cin >> numDoors;
    cout << endl;


    PopulateDoors(doors, numDoors);

    /*for (int i = 0; i < numDoors; i++){
        cout << doors.at(i) << " ";
    }*/
    for (int i = 0; i < numDoors; i++){
        cout << "? ";
    }
    cout << endl;


    cout << "Enter your guess (0-" << (numDoors-1) << "): ";
    cin >> userGuess;
    cout << endl;

    hiddenDoor = DoorToNotReveal(doors, userGuess);
    cout << "The host has revealed all doors except door #" << hiddenDoor << endl;

    PrintDoors(doors, userGuess, hiddenDoor);


    cout << "Would you like to switch?\n(Enter 'y' to switch, anything else to stay):";
    cin >> doesUserSwitch;
    cout << endl;

    if (doesUserSwitch == 'y'){
        cout << "Switching userGuess to hiddenDoor: " << hiddenDoor << endl << endl << endl << endl;
        userGuess = hiddenDoor;
    }

    if(DoesUserWin(doors, userGuess)){
        cout << "Congratulations! You won (absolutely nothing)!" << endl
            << "(Or, if you must, you won a temporary digital binary digit that has already been erased from memory)" << endl;
    }else {
        int correctAnswer = -1;
        for(int i = 0; i < doors.size(); i++){
            if (doors.at(i)){
                correctAnswer = i;
                break;
            }
        }

        cout << "You did not win. Sorry, the correct answer was door #" << correctAnswer << endl;
    }

    //******************************************************************************************************************

    cout << "\n\n\n\n\nNow we will have the computer simulate this scenario many times. "
        << "Before that, there are a few housekeeping items to take care of." << endl << endl;
    int numSimulations;
    int compGuess;
    int userDefinedPlayStyle;
    enum PLAY_STYLE {SWITCH, STAY, RANDOM};
    PLAY_STYLE compPlay;
    ofstream outFS;
    const string CORRECT_FILE = "correct.bin";




    cout << "Enter the number of simulations you would like me to run: ";
    cin >> numSimulations;
    cout << endl;

    cout << "Enter the number of doors for each simulation: ";
    cin >> numDoors;
    cout << endl;

    cout << "Choose whether you want the computer to switch, stay or randomize its play:" << endl
        << "(Enter 0(switch), 1(stay), 2(rand): ";
    cin >> userDefinedPlayStyle;
    cout << endl;

    switch (userDefinedPlayStyle){
        case 0:
            compPlay = SWITCH;
            break;
        case 1:
            compPlay = STAY;
            break;
        case 2:
            compPlay = RANDOM;
            break;
    }


    outFS.open(CORRECT_FILE, ios::binary);
    if(!outFS.is_open()){
        cout << "Failed to open file: " << CORRECT_FILE;
        return 1;
    }
    cout << "simulation started" << endl;

    for (int simNum = 0; simNum < numSimulations; simNum++){

        PopulateDoors(doors, numDoors);

        compGuess = rand() % numDoors;

        hiddenDoor = DoorToNotReveal(doors, compGuess);

        switch (compPlay){
            case 0:
                //cout << "computer will always switch" << endl;
                compGuess = hiddenDoor;
                break;
            case 1:
                //cout << "computer will always stay" << endl;
                compGuess = compGuess;
                break;
            case 2:
                //cout << "computer will randomly switch or not switch" << endl;
                int doesCompSwitch = rand() % 2;//comp will switch when 0
                //cout << "\tcomputer does switch: " << doesCompSwitch << endl;
                switch (doesCompSwitch){
                    case 0:
                        //cout << "\tthe computer chose to switch" << endl;
                        compGuess = hiddenDoor;
                        break;
                    case 1:
                        //cout << "\tthe computer chose to stay" << endl;
                        compGuess = compGuess;
                        break;
                }
                break;
        }

        outFS << " " << DoesUserWin(doors, compGuess);



        /*char cont;
        cout << "enter any key to continue: ";
        cin >> cont;
        cout << endl;*/
    }
    outFS.close();
    cout << endl;

    //comment this out to stop the simulation from printing every win/loss
    /*ifstream inFS;
    inFS.open(CORRECT_FILE);
    if (!inFS.is_open()){
        cout << "Failed to open file: " << CORRECT_FILE << endl;
        return 1;
    }
    while (!inFS.eof() && inFS.good()){
        bool tempVal;
        inFS >> tempVal;
        cout << tempVal << " ";
    }
    inFS.close();
    cout << endl;*/

    cout << "Simulation complete. Processing data" << endl;

    cout << "The computer guessed correctly " << (FindPercentage(CORRECT_FILE) * 100) << "% of the time" << endl;





}

void PopulateDoors(vector<bool>& doors, const int numDoors){
    //srand(time(0));
    doors.resize(numDoors);
    for (int i = 0; i < numDoors; i++){
        doors.at(i) = false;
    }

    doors.at(rand() % numDoors) = true;
}

int DoorToNotReveal(vector<bool>& doors, int userGuess){
    int doNotReveal;
    if (doors.at(userGuess)){
        //cout << "user chose correctly: choose to not reveal random door" << endl;

        do{
            doNotReveal = rand() % doors.size();
        }while (doNotReveal == userGuess);

    }else {
        //cout << "user chose incorrectly: do not reveal true door" << endl;
        for (int i = 0; i < doors.size(); i++){
            if (doors.at(i)){
                doNotReveal = i;
                break;
            }
        }
    }

    return doNotReveal;
}

void PrintDoors(vector<bool>& doors, int userGuess, int hiddenDoor){
    for (int i = 0; i < doors.size(); i++){
        if (i == userGuess){
            cout << "? ";
        }else if(i == hiddenDoor){
            cout << "? ";
        }else {
            cout << doors.at(i) << " ";
        }
    }
    cout << endl;
}

bool DoesUserWin(const vector<bool>& doors, int userGuess){
    //cout << "userGuess: " << userGuess << " doesWin: " << doors.at(userGuess) << endl;
    return doors.at(userGuess);
}

double FindPercentage(const string fileName){
    ifstream inFS;
    inFS.open(fileName, ios::binary);
    if (!inFS.is_open()){
        cout << "Failed to open file: " << fileName << endl;
        return 0.0;
    }
    int numTrue = 0;
    int numTot = 0;
    while (!inFS.eof() && inFS.good()){
        bool currVal;
        inFS >> currVal;
        if (currVal){
            numTrue++;
            //cout << "found truth :" << currVal << endl;
        }else {
            //cout << "found false: " << currVal << endl;
        }
        numTot++;
    }
    inFS.close();
    return static_cast<double>(numTrue) / numTot;
}
