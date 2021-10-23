#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string FlippedFileName(string oldFileName);

void FlipBoardHoriz(string fileName);

int main() {
    const string GAMESTATE_FILE = "gameState.csv";
    ifstream inFS;
    ofstream outFS;

    outFS.open(GAMESTATE_FILE);
    if (!outFS.is_open()){
        return 1;
    }
    outFS << "1 1 1" << endl
        << "0 0 0" << endl
        << "-1 -1 -1" << endl << endl;
    outFS.close();

    outFS.open(GAMESTATE_FILE, ios::app);
    if (!outFS.is_open()){
        return 1;
    }
    outFS << "1 1 1" << endl
        << "0 -1 0" << endl
        << "-1 0 -1" << endl << endl;
    outFS.close();


    return 0;
}

string FlippedFileName(string oldFileName){
    int index = oldFileName.find(".csv");
    oldFileName.insert(index, "Flipped");
    return oldFileName;
}

void FlipBoardHoriz(string fileName){
    string newFileName = FlippedFileName(fileName);
    ifstream inFS;
    ofstream outFS;
    inFS.open(fileName);
    outFS.open(newFileName);
    for (int i = 0; i < 3; i++){
        int boardRow[3];
        for (int j = 0; j < 3; j++){
            inFS >> boardRow[j];
        }
        for (int j = 2; j >= 0; j--){
            outFS << boardRow[j] << " ";
        }
        outFS << endl;
    }
    inFS.close();
    outFS.close();
}