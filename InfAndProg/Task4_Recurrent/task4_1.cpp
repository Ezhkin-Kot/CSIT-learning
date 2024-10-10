#include <iostream>

void Calc(double term1, double term2, double currentTerm, unsigned int numOfTerms) {
    for (int i = 0; i < numOfTerms; i++) {
        if (i == 1) { // Printing first initial term
            std::cout << term1 << ' ';
            continue;
        }
        if (i == 2) { // Printing second initial term
            std::cout << term2 << ' ';
            continue;
        }
        currentTerm = term2 / 2 + term1 / 3; // Calculating next term
        std::cout << currentTerm << ' '; // Printing current term
        // Updating terms
        term1 = term2;
        term2 = currentTerm;
    }
}

int main() {
    int numOfTerms = 0;
    double term1 = 0.5, term2 = 0.4, currentTerm;
    std::cout << "Enter number of terms: ";
    std::cin >> numOfTerms; // Getting number of terms to print
    // Checking correctness of input
    if (numOfTerms > 0 && std::cin) {
        //Calculating and printing terms
        Calc(term1, term2, currentTerm, numOfTerms);
    }
    else {
        std::cout << "\nError\n";
        return -1;
    }

    return 0;
}
