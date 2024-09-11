#include <iostream>
using namespace std;

int main() {
    // variables declaration
    int n = 0, i = 0;
    int x1, x2, x3, x4;
    bool IsEven;

    cout << "Enter \"n\" and \"i\" numbers: ";
    cin >> n >> i; // getting n and i number
    x1 = 1 << i; // integer equals to 2^i
    // 00000001 = 2^0 = 1
    // i = 5
    //   1 << 1
    // 00100000 = 2^5 = 32

    x2 = (1 << i)| n; // integer with i-th bit equals to 1 and other bits match with n
    // n = 15 = 1111, i = 5
    //   00000001
    //     1 << 1
    //   00100000
    // OR
    //   00001111
    // = 00101111 = 47

    x3 = ~(1 << i) & n; // integer with i-th bit equals to 0 and other bits match with n
    // n = 63, i = 4
    //    00000001
    //       1 < 1
    //    00010000
    //  ~ 11101111
    // AND
    //    00111111
    //    00101111 = 47

    x4 = (1 << i) ^ n; // integer with i-th bit differs from i-th bit of n number and other bits match with n
    // n = 63, i = 4
    //    00000001
    //       1 < 1
    //    00010000
    // XOR
    //    00111111
    //    00101111 = 47

    IsEven = ((n >> 1) << 1) == n; // checking n number for parity
    // n = 10 = 1010             n == 11 = 1011
    // 00001010                  00001011
    //      >>                        >>
    // 00000101                  00000101
    //      <<                        <<
    // 00001010 == 1010          00001010 != 1011
    //  is even                    is odd

    cout << "X1 = " << x1 << endl << "X2 = " << x2 << endl << "X3 = " << x3 << endl << "X4 = " << x4 << endl; // output
    IsEven == 1 ? cout << "n number is even" << endl : cout << "n number is odd" << endl; // output checking for parity

    return 0;
}