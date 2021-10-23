#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <ios>
using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

const double STARTING_HEAT = 100.0;
const double TOLERANCE = 0.1;

const int PRECISION = 3;
const int WIDTH = 9;

bool UpdatePlate(double hotPlate[NUM_ROWS][NUM_COLS]);
void PrintPlate(double hotPlate[NUM_ROWS][NUM_COLS]);
bool OutputToFile(string fileName, double hotPlate[NUM_ROWS][NUM_COLS]);
bool CreateNewFromFile(string fileName, double hotPlate[NUM_ROWS][NUM_COLS]);


int main() {


    //Initialize hotPlate with starting values
    double hotPlate[NUM_ROWS][NUM_COLS];
    for(int row = 0; row < NUM_ROWS; row++){
        for(int col = 0; col < NUM_COLS; col++){
            if(row == 0){
                if((col > 0) && (col < (NUM_COLS - 1))) {
                    hotPlate[row][col] = STARTING_HEAT;
                }
            }else if(row == NUM_ROWS - 1){
                if((col > 0) && (col < (NUM_COLS - 1))){
                    hotPlate[row][col] = STARTING_HEAT;
                }else{
                    hotPlate[row][col] = 0.0;
                }
            }else {
                hotPlate[row][col] = 0.0;
            }
        }
    }

    //printing initial plate values
    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;
    PrintPlate(hotPlate);
    cout << "Printing plate after one iteration..." << endl;
    UpdatePlate(hotPlate);
    PrintPlate(hotPlate);

    bool isStable = false;
    while(!isStable){
        isStable = UpdatePlate(hotPlate);
    }

    cout << "Printing final plate..." << endl;
    PrintPlate(hotPlate);

    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;
    OutputToFile("Hotplate.csv", hotPlate);


    CreateNewFromFile("Inputplate.txt", hotPlate);
    int counter = 0;
    for(int i = 0; i < 3; i++){
        counter++;
        UpdatePlate(hotPlate);
    }
    cout << "Printing input plate after " << counter << " updates..." << endl;
    PrintPlate(hotPlate);

    return 0;
}

bool UpdatePlate(double hotPlate[NUM_ROWS][NUM_COLS]){
    //create a temporary plate to hold the previous values of the hotPlate
    double tempPlate[NUM_ROWS][NUM_COLS];
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
            tempPlate[i][j] = hotPlate[i][j];
        }
    }

    double currAverage;
    for (int i = 1; i < (NUM_ROWS - 1); i++){
        for (int j = 1; j < (NUM_COLS - 1); j++){
            currAverage = (+ tempPlate[i+1][j] + tempPlate[i-1][j] + tempPlate[i][j+1] + tempPlate[i][j-1]) / 4;
            hotPlate[i][j] = currAverage;

        }
    }

    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j< NUM_COLS; j++){
            //goes through every hotplate[i][j]
            if (fabs(hotPlate[i][j] - tempPlate[i][j]) > TOLERANCE){
                return false;
            }
        }
    }
    return true;
}

void PrintPlate(double hotPlate[NUM_ROWS][NUM_COLS]){
    for(int i = 0; i < NUM_ROWS; i++){
        for(int j = 0; j < NUM_COLS; j++){
            if(j == (NUM_COLS - 1)){
                cout << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j];
            }else {
                cout << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j] << ",";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool OutputToFile(string fileName, double hotPlate[NUM_ROWS][NUM_COLS]){
    ofstream outFS;
    outFS.open(fileName);

    if (!outFS.is_open()){
        return false;
    }
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
            if (j == (NUM_COLS - 1)){
                outFS << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j];
            }else{
                outFS << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j] << ",";
            }

        }
        outFS << endl;
    }
    return true;
}

bool CreateNewFromFile(string fileName, double hotPlate[NUM_ROWS][NUM_COLS]){
    ifstream inFS;
    inFS.open(fileName);

    if (!inFS.is_open()){
        return false;
    }

    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
            inFS >> hotPlate[i][j];
        }
    }
    return true;
}