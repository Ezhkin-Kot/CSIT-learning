#include <iostream>
#include <string>
#include <sstream>

int SumOfElems(int* arr, int start, int end, int size) {
    int sum = 0, count = 0;

    for (int i = 0; i < size; i++) {
        if (start <= *(arr + i) && *(arr + i) <= end && (*(arr + i) % 2 == 0 && *(arr + i) != 0)) { // Checking conditions
            sum += *(arr + i); // sum suitable elements
            count++;
        }
    }
    // Checking if there are no suitable elements
    if (count == 0) {
        std::cout << "There are no such elements" << std::endl;
        return 0;
    }

    std::cout << sum << std::endl;
    return sum;
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
    int size, start, end;

    std::cout << "Enter size of array: ";
    std::cin >> size; 
    // Checking correctness of input
    if (!std::cin or size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return 1;
    }

    int* myArray = SetArray(size); // Array generation

    std::cout << std::endl;

    std::cout << "Enter start and end of interval: ";
    std::cin >> start >> end;
    // Checking correctness of input
    if (!std::cin) {
        std::cerr << "Invalid interval" << std::endl;
        delete[] myArray;
        return 2;
    }
    // Swap start with end if start is more than end
    if (start > end) {
        std::swap(start, end);
    }

    // Calculate sum of suitable elements of array
    SumOfElems(myArray, start, end, size);

    delete[] myArray; // Memory cleaning
    return 0;
}