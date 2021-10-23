#include <iostream>
using namespace std;

int main() {
    const char EMPTY_SPACE = '.';
    const char SHIP_SEGMENT = 'x';
    const char SEPARATOR = '-';
    const int NUM_SHIPS = 6;

    int coordinates[NUM_SHIPS][2];//x cor are [0] and y cor are [1]
    int height, width;
    cin >> width >> height;
    for(int i = 0; i < NUM_SHIPS; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            //check to see if the current coordinates are part of a ship
            bool isShip = false;
            for(int k = 0; k < NUM_SHIPS; k++){
                //flipped, since x-cor corresponds with width,
                // and y-cor corresponds with height
                if(i == coordinates[k][1] && j == coordinates[k][0]){
                    isShip = true;
                }
            }

            //print battlefield
            if(isShip){
                cout << SHIP_SEGMENT;
            }else {
                cout << EMPTY_SPACE;
            }
        }
        cout << endl;

        if(i == (height/2)-1){
            for(int k = 0; k < width; k++){
                cout << SEPARATOR;
            }
            cout << endl;
        }
    }



}
