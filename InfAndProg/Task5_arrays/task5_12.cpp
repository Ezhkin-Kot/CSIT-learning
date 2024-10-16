#include <iostream>

int ReverseMaxElems(int* arr, int size) {
    int count = 0;
    int max = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

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

int main() {
    srand(time(NULL));
    int size;

    std::cout << "Enter size of array: ";
    std::cin >> size;
    if (!std::cin or size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return 1;
    }

    int* myArray = new int[size];

    for (int i = 0; i < size; i++) {
        *(myArray + i) = rand() % 100;
        std::cout << *(myArray + i) << " ";
    }
    std::cout << std::endl;

    ReverseMaxElems(myArray, size);

    delete[] myArray;
    return 0;
}