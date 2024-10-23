#include <iostream>
#include <sstream>

int** SetArray(int *size) {
    std::cout << "Enter size of array: ";
    std::cin >> *size;
    // Checking correctness of input
    if (!std::cin or *size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
    }

    // Memory allocation
    int **array = new int* [*size];
    for (int i = 0; i < *size; i++) {
        array[i] = new int[*size];
    }

    // Filling an array 
    int number = 0;
    for (int col = 0; col < *size; col++) {
        if (col % 2 == 0) { // If column is even, numbers go from top to bottom
            for (int row = 0; row < *size; row++) {
                array[row][col] = number;
                number++;
            }
        }
        else { // If column is not even, numbers go from bottom to top
            for (int row = *size - 1; row >= 0; row--) {
                array[row][col] = number;
                number++;
            }
        }
    }

    std::cout << std::endl;
    return array;
}

void printArray(int **array, int *size) {
    // Output an array
    for (int i = 0; i < *size; i++, std::cout << std::endl) {
        for (int j = 0; j < *size; j++) {
            std::cout << array[i][j] << "\t";
        }
    }
}

int main() {
    int size = 0;
    int **array = SetArray(&size);
    printArray(array, &size);

    // Memory cleaning
    for (int i = 0; i < size; i++) {
        delete [] array[i];
    }
    delete [] array;
}