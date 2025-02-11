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

void PrintCoeffs(int **array, const int *size) {
    std::cout << "coeffs (1 + x)^n: \n";
    // Printing coeffs of polynomial in n degree
    for (int j = 0; j <= *size; j++) {
            std::cout << array[*size][j] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int size;
    int **myArray = GetPascalTriangle(&size); // Getting array with coeffs of polynomials in n degree

    PrintCoeffs(myArray, &size); // Printing coeffs of polynomial in n degree

    // Memory cleaning
    for (int i = 0; i < size; i++) {
        delete [] myArray[i];
    }
    delete [] myArray;
    return 0;
}