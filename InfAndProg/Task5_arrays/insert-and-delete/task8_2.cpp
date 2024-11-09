#include <iostream>

int* SetArray(int *size) {
    std::cout << "Enter size of array: ";
    std::cin >> *size;
    // Checking correctness of input
    if (!std::cin or *size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
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

void DeleteElems(int *array, int *size) {
    int elemToDelete;
    std::cout << "Enter element to delete: ";
    std::cin >> elemToDelete;

    for (int i = 0; i < *size; ) {
        if (array[i] == elemToDelete) {
            (*size)--; // "resize" array
            for (int j = i; j < *size; j++) {
                array[j] = array[j + 1]; // removing i-th element and shifting end of array
            }
        }
        else {
            i++; // If element don't equals to elemToDelete
        }
    }
}

void printArray(int *array, int *size) {
    // Output an array
    for (int i = 0; i < *size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size = 0;
    int *array = SetArray(&size);

    DeleteElems(array, &size);
    printArray(array, &size);

    // Memory cleaning
    delete [] array;
}