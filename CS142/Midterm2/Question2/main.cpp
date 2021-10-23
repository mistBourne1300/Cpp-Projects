#include <iostream>
#include <string>
using namespace std;

/*
 * Utah:        37-41, 109-114  Colorado:    37-41, 102-109
 * Arizona:     31-37, 109-114  New Mexico:  31-37, 102-109
 * Outside these boundaries, check for North/South first, then East/West
 *
 *
 * Utah:        38.9    110
 * Colorado:    38.9    107
 * Arizona:     35.5    110
 * New Mexico:  35.5    107
 * North:       42      115
 * South:       30      115
 * East:        35.5    100
 * West:        35.5    115
 */


int main() {
    double latitude = 0, longitude = 0;
    string place;
    cout << "Please enter the latitude of the position: " << endl;
    cin >> latitude;
    cout << "Please enter the longitude of the position: " << endl;
    cin >> longitude;


    //check to see if it's north or south
    if(latitude < 31){
        place = "the South";
    }
    else if(latitude > 41){
        place = "the North";
    }
    else if(longitude < 102){
        place = "the East";
    }
    else if(longitude > 114){
        place = "the West";
    }
    else if(latitude < 37){ //we know it's greater than 31, so I can probably get rid of this
        if(longitude < 109){
            place = "New Mexico";
        }
        else{ // redundant logic, clean up
            place = "Arizona";
        }
    }else if(latitude > 37 && latitude < 41){
        if(longitude < 109){
            place = "Colorado";
        }
        else{ // redundant logic, clean up
            place = "Utah";
        }
    }

    cout << "The position is in " << place << endl;

}
