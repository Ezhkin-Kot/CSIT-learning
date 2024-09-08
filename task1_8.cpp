#include <iostream>
#include <cmath> //importing a math library
using namespace std;

//variables declaration
double x;
double y;

double F(double x, double y) { //math function
    double result = sqrt((sqrt(cos(x) + sin(y)) + exp(x + y)) / sqrt(x + y + log(x) * log(x)));

    return result;
}

int main() {
    cout << "X = ";
    cin >> x; //getting a first number
    cout << "Y = ";
    cin >> y; //getting a second number

    cout << F(x, y) << endl; //calling a function and outputting an answer

    return 0;
}
