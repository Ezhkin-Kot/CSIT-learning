#include <iostream>

int Calc(int startNum, int endNum, int step) {
    // Exceptions catching: 
    for (int x = startNum; x <= endNum; x += step) {
        if (2 * x - 8 == 1) { // log(1) = 0
            std::cout << "Error: Division by zero" << std::endl;
            continue;
        }
        if (x*x - 1 < 0) {
            std::cout << "Error: Square root of a negative number" << std::endl;
            continue;
        }
        if (x <= 4) {
            std::cout << "Error: Logarithm of a non-positive number" << std::endl;
            continue;
        }
        // Normal output: 
        std::cout << sqrt(x*x - 1.0)/log(2.0*x - 8.0) << std::endl;
    }
    return 0;
}

int main() {
    int startNum, endNum, step;
    std::cout << "Enter numbers in format \"start end step\" separated by space: ";
    std::cin >> startNum >> endNum >> step; // getting numbers

    Calc(startNum, endNum, step); // function calling

    return 0;
}