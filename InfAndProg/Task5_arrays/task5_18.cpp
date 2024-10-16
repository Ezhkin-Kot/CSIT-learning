#include <iostream>

int ReverseMaxElems(int* arr, int size) {
    int count = 0;
    int max = *arr, maxIndex = 0;
    int min = *arr, minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) >= max) {
            max = *(arr + i);
            maxIndex = i;
        }
        if (*(arr + i) < min) {
            min = *(arr + i);
            minIndex = i;
        }
    }

    std::swap(arr[maxIndex], arr[minIndex]);

    for (int i = 0; i < size; i++) {
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