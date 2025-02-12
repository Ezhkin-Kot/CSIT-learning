#include <iostream>
#include <string>
#include <sstream>

int ReverseMaxElems(int* arr, int size) {
    int count = 0;
    int max = *arr; 

    // Finding max element of array
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    // Inverting max elements
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == max) {
            *(arr + i) = *(arr + i) * (-1);
            count++;
        }
        std::cout << *(arr + i) << " ";
    }
    
    std::cout << std::endl;

    return count;
}

int* SetArray(int size) {
    int* myArray = new int[size]; // Memory allocation

    // Chosing random or manual array setting
    char choise;
    std::cout << "Random or manual array setting? Type \"R\" to random or \"M\" to manual: ";
    std::cin >> choise;
    switch (choise)
    {
        case 'R': {
            srand(time(NULL)); // initialize random generator
             // Randomise elements of array
            for (int i = 0; i < size; i++) {
                *(myArray + i) = rand() % 100;
                std::cout << *(myArray + i) << " ";
            }
            break;
        }
        case 'M': {
            std::string input;
            std::cout << "Enter array elements separated by space: ";
            std::cin.get(); // Getting input elements
            std::getline(std::cin, input);
            std::stringstream inputStream(input); // Create stringstream to convert string into array
            // Array setting
            for (int i = 0; i < size; i++) {
                inputStream >> *(myArray + i);
                std::cout << *(myArray + i) << " ";
            }
            break;
        }
        default: {
            break;
        }
    }

    std::cout << std::endl;
    return myArray;
}

int main() {
    srand(time(NULL)); // Initialize random generator
    int size;

    std::cout << "Enter size of array: ";
    std::cin >> size;
    // Checking correctness of input
    if (!std::cin or size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return 1;
    }

    int* myArray = SetArray(size); // Array generation

    std::cout << std::endl;

    // Inverting max elements
    ReverseMaxElems(myArray, size);

    delete[] myArray; // Memory cleaning
    return 0;
}