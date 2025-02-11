#include <iostream>
#include <cmath>
using namespace std;

int Calc(double x) {
    // exceptions cathing
    if (x > 4) {
        cout << "Root of a negative number" << endl;
        return 0;
    }
    if (x == 4) {
        cout << "Division by zero" << endl;
        return 0;
    }
    if (x * x <= 9) {
        cout << "Logarithm of a non-positive number" << endl;
        return 0;
    }

    // answer output
    cout << "F(x) = " << sqrt(4.0 - x)/(x*x*x - 64.0) + log(x*x - 9.0) << endl;
    return 1;
}
int main() {
    double x;
    cout << "X = ";
    cin >> x; // getting number "X"

    Calc(x); // function calling

    return 0;
}