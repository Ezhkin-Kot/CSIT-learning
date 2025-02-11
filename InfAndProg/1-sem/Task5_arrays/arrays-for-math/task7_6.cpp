#include<iostream>

// Calculating Pascal triangle
int** GetPascalTriangle(int *size) {
    std::cout <<"n = ";
    std::cin >> *size; // input degree (count of strings of triangle)
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
        // Calculating coeffs of polynominal in n degree
        for (int j = 1; j < i; j++) {
            myArray[i][j] = myArray[i-1][j-1] + myArray[i-1][j];
        }
        myArray[i][i] = 1;
    }

    return myArray;
}

void PrintCoeffs(const int* P, int *size) {
    int A;
    std::cout << "A = ";
    std::cin >> A; // Input A number

    // Memory allocation
    int* result = new int[*size + 3];
    for (int i = 0; i < *size + 3; ++i) {
        result[i] = 0;
    }

    // Calculating (x^2 - A) * P(x)
    for (int i = 0; i <= *size; ++i) {
        result[i + 2] += P[i];         // Умножение на x^2
        result[i] += -A * P[i];        // Умножение на -A
    }

    // Printing first polynomial
    std::cout << "coeff P(x):" << std::endl;
    for (int i = 0; i <= *size; i++) {
        std::cout << P[i] << ", ";
    }
    std::cout << std::endl;

    // Printing new polynomial
    std::cout << "coeff (x^2 - A)P(x):" << std::endl;
    for (int i = 0; i <= *size + 2; i++) {
        std::cout << result[i] << ", ";
    }
    std::cout << std::endl;

    delete [] result; // Memory cleaning
}

int main(){
    int size;
    int **myArray = GetPascalTriangle(&size); // Getting array with coeffs of polynomials in n degree

    PrintCoeffs(myArray[size], &size); // Printing (x^2 -A) * P(x)

    // Memory cleaning
    for (int i = 0; i < size; i++) {
        delete [] myArray[i];
    }
    delete [] myArray;
    return 0;
}