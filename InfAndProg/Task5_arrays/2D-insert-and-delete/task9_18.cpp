#include <iostream>

int** SetArray(int *size) {
    std::cout << "Enter size of array: ";
    std::cin >> *size;
    // Checking correctness of input
    if (!std::cin || *size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
    }

    // Memory allocation
    int **array = new int* [*size];
    for (int i = 0; i < *size; i++) {
        array[i] = new int[*size];
    }

    // Choosing random or manual array setting
    char choise;
    std::cout << "Random or manual array setting? Type \"R\" to random or \"M\" to manual: ";
    std::cin >> choise;
    switch (choise)
    {
        case 'R': {
            srand(time(NULL)); // Initialize random generator
            // Randomise elements of array
            for (int i = 0; i < *size; i++, std::cout << std::endl) {
                for (int j = 0; j < *size; j++) {
                    array[i][j] = rand() % 100;
                    std::cout << array[i][j] << "\t";
                }
            }
            break;
        }
        case 'M': {
            std::cout << "Enter array: \n";
            for (int i = 0; i < *size; i++) {
                for (int j = 0; j < *size; j++) {
                    std::cin >> array[i][j]; // Manual setting elements of array
                }
            }
            break;
        }
        default: {
            std::cerr << "Invalid choice" << std::endl;
            exit(-1);
        }
    }

    std::cout << std::endl;
    return array;
}

void insertRows(int**& array, int* rows, int* cols) {
    int targetNum;
    std::cout << "Enter number to delete multiples of it: ";
    std::cin >> targetNum;

    // Finding target number in columns
    for (int col = 0; col < *cols;) {
        int found = false;
        for (int row = 0; row < *rows; ++row) {
            if (array[row][col] % targetNum == 0) {
                found = true;
                break;
            }
        }

        if (found) {
            // Shift columns
            for (int row = 0; row < *rows; ++row) {
                for (int tempCol = col; tempCol < *cols - 1; ++tempCol) {
                    array[row][tempCol] = array[row][tempCol + 1];
                }
            }

            (*cols)--; // Resize array
        }
        else {
            col++;
        }
    }
}

void printArray(int** array, int rows, int cols) {
    // Output an array
    for (int i = 0; i < rows; i++, std::cout << std::endl) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << "\t";
        }
    }
}

void deleteArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

int main() {
    int rows, cols;
    int **array = SetArray(&rows);
    cols = rows;
    insertRows(array, &rows, &cols);
    printArray(array, rows, cols);

    // Memory cleaning
    deleteArray(array, rows);
}