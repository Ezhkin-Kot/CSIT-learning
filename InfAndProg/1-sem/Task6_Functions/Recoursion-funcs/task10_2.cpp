#include <iostream>

int recF(int n, int temp = 1) { // Recoursive function
    // Stack overflow catching
    if (n > 19) {
        std::cout << "Too big number. Stack overflow is possible!" << std::endl;
        return 0;
    }

    // Calculating n!!
    temp *= n;
    n -= 2;

    if (n <= 0) {
        return temp;
    }

    return recF(n, temp); // Recursion calling
}

int norecF(int n) { // Non-recoursion function
    // Stack overflow catching
    if (n > 19) {
        std::cout << "Too big number. Stack overflow is possible!" << std::endl;
        return 0;
    }

    int temp = 1;
    // Calculating n!!
    for (int i = n; i > 0; i -= 2) {
        temp *= i;
    }

    return temp;
}

int main() {
    int n, F1, F2;
    std::cout << "Enter number: ";
    std::cin >> n;

    F1 = recF(n); // Recoursion function calling
    F2 = norecF(n); // Non-recoursion function calling
    // Output
    std::cout << "With recoursion: " << F1 << std::endl;
    std::cout << "Without recoursion: " << F2 << std::endl;
    return 0;
}