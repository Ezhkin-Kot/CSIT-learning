#include <iostream>

void printSumOfSquares(int countOfNums) { // finding numbers which is sum of squares of other natural numbers
    for (int num = 0; num < countOfNums; num++) {
        for (int firstDiv = 1; firstDiv < num; firstDiv++) {
            for (int secondDiv = 1; secondDiv < firstDiv; secondDiv++) {
                if (firstDiv*firstDiv + secondDiv*secondDiv == num) {
                    std::cout << num << std::endl; // output numbers
                }
            }
        }
    }
}

int main() {
    int CountOfNums;
    std::cout << "N = ";
    std::cin >> CountOfNums; // getting N number

    printSumOfSquares(CountOfNums); // function calling

    return 0;
}