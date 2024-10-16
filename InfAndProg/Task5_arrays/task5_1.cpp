#include <iostream>

int SumOfElems(int* arr, int start, int end, int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (start <= *(arr + i) && *(arr + i) <= end && (*(arr + i) % 2 == 0 && *(arr + i) != 0)) {
            sum += *(arr + i);
            count++;
        }
    }
    if (count == 0) {
        std::cout << "There are no such elements" << std::endl;
        return 0;
    }

    std::cout << sum << std::endl;
    return sum;
}

int main() {
    srand(time(NULL));
    int size, start, end;

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

    std::cout << "Enter start and end of interval: ";
    std::cin >> start >> end;
    if (!std::cin) {
        std::cerr << "Invalid interval" << std::endl;
        delete[] myArray;
        return 2;
    }
    if (start > end) {
        std::swap(start, end);
    }

    SumOfElems(myArray, start, end, size);

    delete[] myArray;
    return 0;
}