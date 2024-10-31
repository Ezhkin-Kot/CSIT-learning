#include<iostream>

// Calculating Pascal triangle
int** GetPascalTriangle(int *size) {
    std::cout <<"n = ";
    std::cin >> *size; // Input degree (count of strings of triangle)
    // Checking correctness of input
    if (!std::cin or *size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
    }

    // Memory allocation
    int **myArray = new int *[*size + 1];
    for (int i = 0; i <= *size; i++) {
        myArray[i] = new int [i + 1];
    }

    // Start numbers
    myArray[0][0] = 1;
    myArray[1][0] = myArray[1][1] = 1;
    // Setting array
    for (int i = 2; i <= *size; i++) {
        myArray[i][0] = 1;
        // Calculating coeffs of polynomial in n degree
        for (int j = 1; j < i; j++) {
            myArray[i][j] = myArray[i-1][j-1] + myArray[i-1][j];
        }
        myArray[i][i] = 1;
    }

    return myArray;
}

void PrintDerivative(int *firstPolynomial, const int *size) {
    // Memory allocation
    int *result = new int [*size];

    // Calculating derivate of polynomial
    for (int i = 1; i <= *size; i++) {
        result[i-1] = i * firstPolynomial[i];
    }

    // Printing first polynomial
    std::cout << "coeff P(x):" << std::endl;
    for (int i = 0; i <= *size; i++) {
        std::cout << firstPolynomial[i];
        if (i < *size) { std::cout << ", "; }
    }
    std::cout << std::endl;

    // Printing new polynomial
    std::cout << "coeff P'(x):" << std::endl;
    for (int i = 1; i <= *size; i++) {
        std::cout << result[i-1];
        if (i < *size) { std::cout << ", "; }
    }
    std::cout << std::endl;

    delete [] result; // Memory cleaning
}

int main(){
    int size;
    int **myArray = GetPascalTriangle(&size); // Getting array with coeffs of polynomials in n degree

    PrintDerivative(myArray[size], &size); // Output derivate of polyominal

    // Cleaning memory
    for (int i = 0; i < size; i++) {
        delete [] myArray[i];
    }
    delete [] myArray;
    return 0;
}