#include <iostream>

// Function to compute the sum of the series using recursion relation
double Calc(double x, double eps) {
    int maxCountOfIterations = 100;
    double sum = x;  // First term of the series
    double term = x; // Current term of the series
    int n = 1;         // Start with n = 1 for further terms

    // Summing until the term becomes smaller than epsilon
    while (std::abs(term) > eps) {
        term *= -(x * x);   // Update term to x^(2n+1)
        sum += term / (2 * n + 1); // Add the term with the denominator to the sum
        n++;
        // Checking if the series diverges
        if (n > eps && n > maxCountOfIterations) {
            std::cout << "The series diverges for the value of x" << std::endl;
            return NAN;
        }
    }

    return sum;
}

int main() {
    double x, eps;
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    // Checking correctness of input
    if (!std::cin) {
        std::cout << "\nError\n";
        return -1;
    }
    std::cout << "Enter the value of eps: ";
    std::cin >> eps;
    // Checking correctness of input
    if (!std::cin) {
        std::cout << "\nError\n";
        return -1;
    }

    // Calculate the sum of the series
    double result = Calc(x, eps);

    // If result is not NaN, print the result
    if (!std::isnan(result)) {
        std::cout << "The sum of the series = " << result << std::endl;
    }

    return 0;
}