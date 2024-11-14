#include <iostream>

void PrintChristmassTree(int n, int temp = 1, int spaces = 0) {
    if (n <= 0) {
        return; // Exit condition
    }
    if (spaces == 0) {
        spaces = n; // Start count of spaces
    }

    temp += 2; // Updating count of stars
    int tempSpaces = spaces;
    int i = 1;
    while (i <= temp) {
        // Setting spaces for center text align
        for (int space = tempSpaces; space > 0; space--) {
            std::cout << "  ";
        }
        // Printing stars in pyramid form
        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;

        i += 2; // Step
        tempSpaces--; // Spaces reduce
    }

    PrintChristmassTree(n - 1, temp, spaces); // Recursion calling
}

int main() {
    int n;
    std::cout << "Enter n number: ";
    std::cin >> n; // Count of blocks

    PrintChristmassTree(n); // Printing spruce-form figure with symbols "*"
    return 0;
}