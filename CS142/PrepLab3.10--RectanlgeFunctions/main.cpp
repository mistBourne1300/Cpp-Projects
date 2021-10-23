#include <iostream>
#include <iomanip>
using namespace std;

double CalcRectanglePerimeter(double height, double width){
    return ((2 * height) + (2 * width));
}

void PrintRectanglePerimeter(double height, double width){
    double perim = CalcRectanglePerimeter(height, width);
    cout << "A rectangle with height " << fixed << setprecision(1) << height << " and width "
        << width << " has a perimeter of " << perim << "." << endl;
}

void DoubleRectanglePerimeter(double& height, double& width){
    height*=2.0;
    width*=2.0;
}

int main() {
    PrintRectanglePerimeter(4.5, 6.33);
    return 0;
}
