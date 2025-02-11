#include <iostream>
#include <sstream>
#include <cstdlib>

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
            break;
        }
    }

    std::cout << std::endl;
    return array;
}

void insertRows(int**& array, int* rows, int* cols) {
    std::string inputRow;
    int target;

    std::cout << "Enter row to insert: ";
    std::cin.ignore();
    std::getline(std::cin, inputRow);

    std::cout << "Enter number after to insert: ";
    std::cin >> target;

    // Finding target number in rows
    for (int i = 0; i < *rows; ++i) {
        bool found = false;
        for (int j = 0; j < *cols; ++j) {
            if (array[i][j] == target) {
                found = true;
                break;
            }
        }

        if (found) {
            // Resize array
            (*rows)++;
            array = (int**)realloc(array, *rows * sizeof(int*));
            if (!array) {
                std::cerr << "Memory allocation error" << std::endl;
                exit(EXIT_FAILURE);
            }

            // Shift rows
            for (int k = *rows - 1; k > i + 1; --k) {
                array[k] = array[k - 1];
            }

            // Insert new row
            std::istringstream stream(inputRow);
            array[i + 1] = new int[*cols];
            for (int j = 0; j < *cols; ++j) {
                stream >> array[i + 1][j];
            }

            i++; // Skip inserted row
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