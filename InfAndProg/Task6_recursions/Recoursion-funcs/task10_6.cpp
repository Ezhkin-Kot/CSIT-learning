#include <iostream>

int recH(int x, int n) { // Hermit's polynomial
    if (n < 0) {
        return 0; // Exit condition
    }
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2*x;
    }
    return 2*x * recH(x, n - 1) - 2*(n-1) * recH(x, n - 2);
}

int norecH(int x, int n) { // Hermit's polynomial
    int *arrH = new int [n + 1];

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            arrH[i] = 1;
        }
        if (i == 1) {
            arrH[i] = 2*x;
        }
        if (i >= 2) {
            arrH[i] = 2*x * arrH[i - 1] - 2*(i-1) * arrH[i - 2];
        }
    }

    int result = arrH[n];
    delete [] arrH;
    return result;
}

int main() {
    int x, n;
    std::cout << "Enter x number: ";
    std::cin >> x;
    std::cout << "Enter n number: ";
    std::cin >> n;

    int F1 = recH(x, n); // Calculating Hermit's polynomial with recoursion function
    int F2 = norecH(x, n); // Calculating Hermit's polynomial without recoursion function
    std::cout << "With recoursion: " << F1 << std::endl;
    std::cout << "Without recoursion: " << F2 << std::endl;
    return 0;
}