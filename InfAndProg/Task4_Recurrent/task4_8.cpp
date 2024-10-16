#include <iostream>

// Function to compute the sum of the series using recursion relation
double Calc(double x, double eps) {
    int maxCountOfIterations = 100;
    double sum = 1.0;  // First term of the series
    double term = 1.0; // Current term of the series
    int n = 1;         // Start with n = 1 for further terms

    // Summing until the term becomes smaller than epsilon
    while (std::abs(term) > eps) {
        // d = (a[n])/(a[n-1]) = ((-1)^n * x^n)/((-1)^(n-1) * x^(n-1)) = (-1) * x = -x
        term *= -x;    // Calculate the next term using the recurrence relation
        sum += term;   // Add the term to the sum
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
