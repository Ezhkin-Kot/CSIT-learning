#include <iostream>
using namespace std;

int Converter(int A, int X, int Y) {

    int FirstDigit = A / 10; // the first digit of number "A"
    int SecondDigit = A % 10; // the second digit of number "A"

    // checking all conditions and transforming number "A"
    if (FirstDigit < X && SecondDigit > Y) {
        A -= X;
    }
    else if (FirstDigit < X && SecondDigit < Y) {
        A += X;
    }
    else if (FirstDigit > X && SecondDigit > Y) {
        A -= Y;
    }
    else if (FirstDigit > X && SecondDigit < Y) {
        A += Y;
    }
    else {
        A += (X * Y);
    }
    return A;
}

int main() {
    int A, X, Y; // variables declaration

    cout << "Enter a two-digit number" << endl;
    cin >> A; // getting number "A"
    if (A > 99 || A < 10) { // checking correctness of the input
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << "Enter one-digit numbers" << endl << "X = ";
    cin >> X; // getting number "X"
    cout << "Y = ";
    cin >> Y; // getting number "Y"
    if (X > 9 || Y > 9 || X < 0 || Y < 0) { // checking correctness of the input
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << Converter(A, X, Y) << endl; // output

    return 0;
}