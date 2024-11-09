#include <iostream>
#include <cstdlib> // for realloc
#include "/Users/ezhkinkot/Projects/CSIT/CSIT-learning/InfAndProg/myOwnLibs/ArraySetter.h"

int* InsertElems(int* array, int* size) {
    int insertAfterElem, elemToInsert;
    std::cout << "Enter element before witch to insert: ";
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
                array[i++] = elemToInsert; // Insert
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
    SetArray setArray;
    int size = 0;
    int *array = setArray.oneDim(&size);

    array = InsertElems(array, &size);
    printArray(array, &size);

    // Memory cleaning
    delete [] array;
}