#include <iostream>

void PrintPrimeNums(int countOfNums) { // finding prime numbers
    bool isPrime;
    for (int i = 2; countOfNums > 0; i++) {
        isPrime = true;
        for (int divs = 2; divs <= sqrt(i) + 1; divs++) { // searching for divisors of i number
            if (i % divs == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << i << std::endl; // output prime numbers
            countOfNums--; // Countdown of prime numbers
        }
    }
}

int main() {
    int CountOfNums;
    std::cout << "N = ";
    std::cin >> CountOfNums; // getting N number

    PrintPrimeNums(CountOfNums); // function calling

    return 0;
}