#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> setVector()
{
    int n;
    std::vector<int> vec;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // Vector filling
    std::cout << "Enter vector elements separated by space: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }

    return vec;
}

std::unordered_set<int> extractDigits(int number) {
    std::unordered_set<int> digits;
    while (number > 0) {
        digits.insert(number % 10);
        number /= 10;
    }
    return digits;
}

int main() {
    std::vector<int> numbers = setVector();

    std::unordered_set<int> twoDigitDigits;
    std::unordered_set<int> otherDigits;

    for (int number : numbers) {
        std::unordered_set<int> digits = extractDigits(number);

        // Number 0 is not processing with extractDigits
        if (number == 0) {
            digits.insert(0);
        } else {
            digits = extractDigits(number);
        }

        if (number >= 10 && number <= 99) {
            twoDigitDigits.insert(digits.begin(), digits.end());
        } else {
            otherDigits.insert(digits.begin(), digits.end());
        }
    }

    // Find digits which are only in two-digit numbers
    std::vector<int> result;
    for (int digit : twoDigitDigits) {
        if (otherDigits.find(digit) == otherDigits.end()) {
            result.push_back(digit);
        }
    }

    // Sorting result
    std::sort(result.begin(), result.end());

    // Result output
    std::cout << "Digits which are only in two-digit numbers: ";
    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
15 203 47 8 91 62 7 34 50 20
*/