#include <iostream>
#include <cmath> //importing a math library
using namespace std;

//variables declaration
double x;
double y;

double F(double x, double y) { //math function
    double result = sqrt(log(cos(x + y) * cos(x + y)/sin((x + y) * (x + y))) * log(cos(x + y) * cos(x + y)/sin((x + y) * (x + y))) + exp(x * x * y));

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
