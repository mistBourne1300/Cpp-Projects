#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double BIG_G = 6.67259 * pow(10.0, -11.0);
    const int SPEED_OF_LIGHT = 299792458;
    double objectMass;
    double schwarzchildRadius;
    char unitBase;

    do {
        cout << "Would you like the metric or imperial system? (enter 'm' or 'i'):";
        cin >> unitBase;
        cout << endl;
    } while ((unitBase != 'm') && (unitBase != 'i'));

    if (unitBase == 'm') {
        cout << "Enter your mass in kilos: ";
        cin >> objectMass;
        cout << endl;
        schwarzchildRadius = (2 * BIG_G * objectMass) / pow(SPEED_OF_LIGHT, 2);
        cout << "Your Schwarzchild Radius is " << schwarzchildRadius << " meters." << endl;
    }else if(unitBase == 'i'){
        cout << "Enter your weight in pounds: ";
        cin >> objectMass;
        cout << endl;
        objectMass = objectMass * 0.453592;
        schwarzchildRadius = (2 * BIG_G * objectMass) / pow(SPEED_OF_LIGHT, 2);
        schwarzchildRadius = schwarzchildRadius * 3.28084;
        cout << "Your Schwarzchild Radius is " << schwarzchildRadius << " feet." << endl;
    }else {
        cout << "That is not a proper input. How did you get past my do-while loop?" << endl;
    }

    return 0;

}
