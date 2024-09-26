#include <iostream>

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = i; k > 0; k--) { // countdown with output in line
                std::cout << j*k << " ";
            }
            std::cout << std::endl; // line break
        }
    }
    return 0;
}