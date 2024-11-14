#include <iostream>

int DecToBin(int dec, std::string bin = "") { // Calculating binary form of decimal number
    bin = static_cast<char>('0' + dec % 2) + bin; // temporary binary number
    if (dec > 1) {
        return DecToBin(dec / 2, bin); // Recursion calling
    }
    return stoi(bin); // Outputting binary number
}

int main() {
    int x;
    std::cout << "Enter x number: ";
    std::cin >> x;

    int F = DecToBin(x); // Getting binary x
    std::cout << F << std::endl; // Output
    return 0;
}