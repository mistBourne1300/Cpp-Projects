#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double CalcRectanglePerimeter(double height, double width);

void PrintRectanglePerimeter(double height, double width);

void DoubleRectanglePerimeter(double& height, double& width);

double CalcCircumferenceOfCircle(double radius);

double CalcAreaOfCircle(double radius);

double CalcVolumeOfSphere(double radius);

void Swap(double& number1, double& number2);

void Swap(int& number1, int& number2);

const double PI = 3.14;


//main function
int main(){
    cout << "Getting this line to print earns you points!" << endl;

    double height = 0.0;
    double width = 0.0;

    cin >> height >> width;

    PrintRectanglePerimeter(height, width);
    cout << CalcRectanglePerimeter(height, width) << std::endl;
    cout << "... about to double height and width..." << endl;
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);


    return 0;
}

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

double CalcCircumferenceOfCircle(double radius){
    return 2 * PI * radius;
}

double CalcAreaOfCircle(double radius){
    return PI * radius * radius;
}

double CalcVolumeOfSphere(double radius){
    return (4.0/3.0) * PI * (radius * radius * radius);
}

void Swap(double& number1, double& number2){
    double temp = number1;
    number1 = number2;
    number2 = temp;
}

void Swap(int& number1, int& number2){
    int temp = number1;
    number1 = number2;
    number2 = temp;
}