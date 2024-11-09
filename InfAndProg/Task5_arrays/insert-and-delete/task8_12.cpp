#include <iostream>
#include <cstdlib> // for realloc

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

int* InsertElems(int* array, int* size) {
    int insertAfterElem, elemToInsert;
    std::cout << "Enter element after witch to insert: ";
    std::cin >> insertAfterElem;
    std::cout << "Enter element to insert: ";
    std::cin >> elemToInsert;

    // Search elements in array
    int count = 0;
    for (int i = 0; i < *size; i++) {
        if (array[i] == insertAfterElem) {
            count++;
        }
    }

    // Resize array for insert
    if (count > 0) {
        const int oldSize = *size;
        const int newSize = *size + count;

        array = (int*)realloc(array, newSize * sizeof(int));
        if (!array) {
            std::cout << "Memory allocation error" << std::endl;
            delete [] array;
            return nullptr;
        }

        // Inserting elements
        *size = newSize;
        for (int i = 0; i < newSize; i++) {
            if (array[i] == insertAfterElem) {
                // Shifting end of array
                for (int j = *size - 1; j > i; j--) {
                    array[j] = array[j - 1];
                }
                array[++i] = elemToInsert; // Insert
            }
        }
    }
    else {
        std::cout << "Element not found: " << insertAfterElem;
    }

    return array;
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

    array = InsertElems(array, &size);
    printArray(array, &size);

    // Memory cleaning
    delete [] array;
}