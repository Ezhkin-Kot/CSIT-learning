#include <iostream>
#include <cmath> //importing a math library
using namespace std;

//variables declaration
double x;
double y;

double F(double x, double y) { //math function
    double result = 2.0/3.0 * sin(sqrt((x * x - y * y) / exp(x + y) + x*x * y*y)) + (cos(x) + sin(y))/2.0;

    return result;
}

int main() {
    cout << "X = ";
    cin >> x; //getting a first number
    cout << "Y = ";
    cin >> y; //getting a second number

    cout << F(x, y) << endl; //calling a function and output answer

    return 0;
}
