#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <ios>
using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

class HotPlate {
    double hotPlate[NUM_ROWS][NUM_COLS];
    double lastPlate[NUM_ROWS][NUM_COLS];

    int numRows;
    int numCols;

    const double STARTING_HEAT = 100.0;
    const double TOLERANCE = 0.1;

    const int PRECISION = 3;
    const int WIDTH = 9;
public:
    bool CreateNewFromFile(string fileName){
        ifstream inFS;
        inFS.open(fileName);

        if (!inFS.is_open()){
            return false;
        }

        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                inFS >> hotPlate[i][j];
            }
        }
        return true;
    }

    void CreateNewPlate(int rows, int cols){
        numRows = rows;
        numCols = cols;

        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                if (i==0){
                    if ((j > 0) && (j < (numCols - 1))) {
                        hotPlate[i][j] = STARTING_HEAT;
                    }
                }else if(i == (numRows - 1)) {
                    if ((j > 0) && (j < (numCols - 1))) {
                        hotPlate[i][j] = STARTING_HEAT;
                    }else {
                        hotPlate[i][j] = 0.0;
                    }
                }else {
                    hotPlate[i][j] = 0.0;
                }
            }
        }
    }

    void UpdatePlate(){
        double tempPlate[numRows][numCols];
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                tempPlate[i][j] = hotPlate[i][j];
            }
        }

        double currAverage;
        for (int i = 1; i < (numRows - 1); i++){
            for (int j = 1; j < (numCols - 1); j++){
                currAverage = (+ tempPlate[i+1][j] + tempPlate[i-1][j] + tempPlate[i][j+1] + tempPlate[i][j-1]) / 4;
                hotPlate[i][j] = currAverage;

            }
        }
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                lastPlate[i][j] = tempPlate[i][j];
            }
        }
    }

    bool IsStable(){

        for (int i = 0; i < numRows; i++){
            for (int j = 0; j< numCols; j++){
                //goes through every hotplate[i][j]
                if (fabs(hotPlate[i][j] - lastPlate[i][j]) > TOLERANCE){
                    return false;
                }
            }
        }
        return true;
    }

    void PrintMe(){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                if (j == (numCols - 1)){
                    cout << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j];
                }else{
                    cout << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j] << ",";
                }

            }
            cout << endl;
        }
        cout << endl;
    }

    bool OutputToFile(string fileName){
        ofstream outFS;
        outFS.open(fileName);

        if (!outFS.is_open()){
            return false;
        }
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                if (j == (numCols - 1)){
                    outFS << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j];
                }else{
                    outFS << setprecision(PRECISION) << fixed << setw(WIDTH) << hotPlate[i][j] << ",";
                }

            }
            outFS << endl;
        }
        return true;
    }
};

int main() {
    cout << "Hotplate simulator" << endl << endl;

    HotPlate shardPlate;
    shardPlate.CreateNewPlate(NUM_ROWS, NUM_COLS);

    cout << "Printing the initial plate values..." << endl;
    shardPlate.PrintMe();

    cout << "Printing plate after one iteration..." << endl;
    shardPlate.UpdatePlate();
    shardPlate.PrintMe();

    int counter = 1;
    while (!shardPlate.IsStable()){
        //cout << "Iteration " << counter++ << ":" << endl;
        //shardPlate.PrintMe();
        shardPlate.UpdatePlate();
    }

    cout << "Printing final plate..." << endl;
    //cout << "It took " << counter << " iterations for the plate to stabilize." << endl;
    shardPlate.PrintMe();

    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;
    shardPlate.OutputToFile("Hotplate.csv");

    /*cout << endl << endl << endl;
    cout << "Now inputting plate from file Inputplate.txt.";
    cout << endl << endl << endl;*/

    shardPlate.CreateNewFromFile("Inputplate.txt");
    counter = 0;
    for (int i = 0; i < 3; i++){
        counter++;
        /*shardPlate.PrintMe();
        cout << endl << endl;*/
        shardPlate.UpdatePlate();
    }
    cout << "Printing input plate after " << counter << " updates..." << endl;
    shardPlate.PrintMe();

    return 0;
}