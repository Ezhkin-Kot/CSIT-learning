#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

int main() {
    // File opening
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error. Can't open file" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            // Check if the word is a number
            if (std::all_of(word.begin(), word.end(), ::isalpha)) {
                wordFrequency[word]++;
            }
        }
    }

    inputFile.close();

    std::multimap<int, std::string> frequencyMap;
    for (const auto& pair : wordFrequency) {
        frequencyMap.emplace(pair.second, pair.first);
    }

    int k;
    std::cout << "Enter count of words (k): ";
    std::cin >> k;

    // Result output
    std::cout << "Words which are less common than others:" << std::endl;
    int count = 0;
    for (const auto& pair : frequencyMap) {
        if (count >= k)
        {
            break;
        }
        std::cout << pair.second << " (frequency: " << pair.first << ")" << std::endl;
        ++count;
    }

    return 0;
}