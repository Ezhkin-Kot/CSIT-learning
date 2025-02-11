#include <iostream>
#include <string>
using namespace std;
//constants declaration
const int FIRSTNUM = 31;
const int SECONDNUM = 48;

string converter(string stringX) {
    int Ydigits[4] = {}; //array initialization
    int firstX = stringX[0] - '0'; //conversion first char to integer
    int secondX = stringX[1] - '0'; //conversion second char to integer

    //calculating final number
    Ydigits[0] = FIRSTNUM % firstX;
    Ydigits[2] = FIRSTNUM % secondX;
    Ydigits[1] = SECONDNUM % firstX;
    Ydigits[3] = SECONDNUM % secondX;
    // conversion array to string
    string y;
    for (int i = 0; i < 4; i++) {
        y += to_string(Ydigits[i]);
    }

    return y;
}
int main() {
    int x;
    cout << "Enter a two-digit number: ";
    cin >> x; //getting a two-digit number
    if (x < 10 || x > 99 or x % 10 == 0) { //checking the count of digits of a number
        cout << "Invalid input" << endl;
        return 0;
    }
    string stringX = to_string(x); //conversing integer to string
    cout << converter(stringX) << endl; //calling a function and output answer
    return 0;
}