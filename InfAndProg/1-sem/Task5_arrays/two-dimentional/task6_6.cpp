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
            for (int i = 0; i < *size; i++) {
                std::cout << "Введите элементы " << i + 1 << "-й строки через пробел: ";
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

void replaceRows(int **array, int *size) {
    int temp = 0, minIndex = 0, maxIndex = 0;
    int min = array[0][0]; // Min element of array
    int max = array[0][0]; // Max element of array

    // Finding columns with min and max elements
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
                minIndex = i;
            }
            if (array[i][j] > max) {
                max = array[i][j];
                maxIndex = i;
            }
        }
    }

    // Replacing columns with min and max elements
    for (int j = 0; j < *size; j++) {
        temp = array[minIndex][j];
        array[minIndex][j] = array[maxIndex][j];
        array[maxIndex][j] = temp;
    }
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
    replaceRows(array, &size);
    printArray(array, &size);

    // Memory cleaning
    for (int i = 0; i < size; i++) {
        delete [] array[i];
    }
    delete [] array;
}