#include <iostream>
#include <string>
using namespace std;

string converter(string stringX) {
    //arrays initialization
    int Ydigits[4] = {};
    int Xdigits[4] = {};

    //splitting x number into digits
    for (int i = 0; i < 4; i++) {
        Xdigits[i] = stringX[i] - '0';
    }

    //calculating final number
    Ydigits[0] = (Xdigits[0] + Xdigits[1]) % 10;
    Ydigits[1] = (Xdigits[1] + Xdigits[2]) % Xdigits[0];
    Ydigits[2] = (Xdigits[0] + Xdigits[1] + Xdigits[2] + Xdigits[3]) % Xdigits[0];
    Ydigits[3] = abs(Xdigits[1] - Xdigits[3]);

    // conversion array to string
    string y;
    for (int i = 0; i < 4; i++) {
        y += to_string(Ydigits[i]);
    }

    return y;
}
int main() {
    int x;
    cout << "Enter a four-digit number: ";
    cin >> x; //getting a four-digit number
    if (x < 1000 || x > 9999) { //checking the count of digits of a number
        cout << "Invalid input" << endl;
        return 0;
    }
    string stringX = to_string(x); //conversing integer to string
    cout << converter(stringX) << endl; //calling a function and output answer
    return 0;
}