#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
using namespace std;

int main() {
    double wallHeight = 0.0;
    double wallWidth = 0.0;
    double wallArea = 0.0;
    double cansPaintFrac = 0.0;
    int cansPaint = 0;

    cout << "Enter wall height (feet): ";
    cin  >> wallHeight;
    cout << endl;

    cout << "Enter wall width (feet): ";
    cin >> wallWidth;
    cout << endl;

    // Calculate and output wall area
    wallArea = wallHeight * wallWidth;
    cout << "Wall area: " << wallArea << " square feet" << endl;

    cansPaintFrac = wallArea / 350;

    cansPaint = ceil(cansPaintFrac);

    cout << "Paint needed: " << cansPaintFrac << " gallons" << endl;
    cout << "Cans needed: " << cansPaint << " can(s)" << endl;

    return 0;
}