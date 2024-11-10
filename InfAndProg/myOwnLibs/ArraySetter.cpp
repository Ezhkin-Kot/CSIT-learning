#include "ArraySetter.h"

SetArray::SetArray()
{
}

int *SetArray::oneDim(int *size)
{
    if (!*size) {
            std::cout << "Enter size of array: ";
        std::cin >> *size;
        // Checking correctness of input
        if (!std::cin or *size < 1) {
            std::cerr << "Invalid size" << std::endl;
            return nullptr;
        }
    }
    

    // Memory allocation
    int *array = new int [*size];

    // Choosing random or manual array setting
    char choise;
    std::cout << "Random or manual array setting? Type \"R\" to random or \"M\" to manual: ";
    std::cin >> choise;
    switch (choise)
    {
        case 'R': {
            srand(time(NULL)); // Initialize random generator
            // Randomise elements of array
            for (int i = 0; i < *size; i++) {
                array[i] = rand() % 100;
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 'M': {
            std::cout << "Enter array elements separated by space: ";
            for (int i = 0; i < *size; i++) {
                std::cin >> array[i]; // Manual setting elements of array
            }
            break;
        }
        default: {
            break;
        }
    }

    return array;
}

int** SetArray::twoDim(int *size) {
    if (!*size) {
        std::cout << "Enter size of array: ";
        std::cin >> *size;
        // Checking correctness of input
        if (!std::cin or *size < 1) {
            std::cerr << "Invalid size" << std::endl;
            return nullptr;
        }
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
                std::cout << "Enter elements of" << i + 1 << "-th row separated by space: ";
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

int** SetArray::twoDim(int *rows, int *cols) {
    if (!*rows) {
        std::cout << "Enter count of rows of array: ";
        std::cin >> *rows;
        // Checking correctness of input
        if (!std::cin or *rows < 1) {
            std::cerr << "Invalid size" << std::endl;
            return nullptr;
        }
    }

    if (!*cols) {
        std::cout << "Enter count of columns of array: ";
        std::cin >> *cols;
        // Checking correctness of input
        if (!std::cin or *cols < 1) {
            std::cerr << "Invalid size" << std::endl;
            return nullptr;
        }
    }

    // Memory allocation
    int **array = new int* [*rows];
    for (int i = 0; i < *rows; i++) {
        array[i] = new int[*cols];
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
            for (int i = 0; i < *rows; i++, std::cout << std::endl) {
                for (int j = 0; j < *cols; j++) {
                    array[i][j] = rand() % 100;
                    std::cout << array[i][j] << "\t";
                }
            }
            break;
        }
        case 'M': {
            for (int i = 0; i < *rows; i++) {
                std::cout << "Enter elements of" << i + 1 << "-th row separated by space: ";
                for (int j = 0; j < *cols; j++) {
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