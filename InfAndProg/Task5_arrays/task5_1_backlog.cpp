#include <iostream>
#include <sstream>

int SumOfElems(int* arr, int* start, int* end, int* size) {
    int sum = 0;
    for (int i = 0; i < (*size); i++) {
        if ((*start) <= *(arr + i) <= (*end) && *(arr + i) % 2 == 0 && *(arr + i) != 0) {
            sum += *(arr + i);
        }
    }
    std::cout << sum;
    return sum;
}

int* SetArr(int* start, int* end, int* size) {
    std::string input;
    int numOfArr;

    std::cout << "Enter size of array: ";
    std::cin >> *size;
    if (!std::cin or (*size) < 1) {
        std::cerr << "Invalid size" << std::endl;
        return 0;
    }
    int* myArray = new int[*size];

    std::cout << "Enter array elements separated by space: ";
    std::getline(std::cin, input);
    std::stringstream inputStream(input);

    for (int i = 0; i < (*size); i++) {
        inputStream >> numOfArr;
        *(myArray + i) = numOfArr;
    }

    std::cout << "Enter start and end of interval: ";
    std::cin >> *start >> *end;
    if (!std::cin or (*end) < (*start)) {
        std::cerr << "Invalid interval" << std::endl;
        return 0;
    }

    for (int i = 0; i < (*size); i++) {
        std::cout << *(myArray + i) << " ";
    }

    return myArray;
}

int main() {
    int Start, End, Size;
    int* start = &Start, * end = &End, * size = &Size;
    int* myArray = SetArr(start, end, size);
    SumOfElems(myArray, start, end, size);

    delete[] myArray;
    delete[] start;
    delete[] end;
    delete[] size;
    return 0;
}