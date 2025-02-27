#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cctype>

// Convert string to lower case
std::string toLowerCase(const std::string& str) {
    std::string result = str;
    for (char& ch : result) {
        ch = std::tolower(ch);
    }
    return result;
}

int main() {
    std::string text;
    std::cout << "Enter text:" << std::endl;
    std::getline(std::cin, text);

    std::unordered_set<std::string> narrativeWords;    // Words from narrative sentences
    std::unordered_set<std::string> exclamatoryWords;  // Words from exclamatory sentences

    size_t start = 0;
    size_t end = 0;

    while ((end = text.find_first_of(".!?", start)) != std::string::npos) {
        char lastChar = text[end]; // Punctuation mark
        std::string sentence = text.substr(start, end - start);

        // Removing spaces in the start and the end of sentence
        sentence.erase(0, sentence.find_first_not_of(" \t\r\n"));
        sentence.erase(sentence.find_last_not_of(" \t\r\n") + 1);

        if (!sentence.empty()) {
            std::istringstream wordStream(sentence);
            std::string word;

            while (wordStream >> word) {
                word = toLowerCase(word); // Convert to lower case

                if (!word.empty()) {
                    if (lastChar == '.') {
                        narrativeWords.insert(word);
                    } else if (lastChar == '!') {
                        exclamatoryWords.insert(word);
                    }
                }
            }
        }

        start = end + 1;
        while (start < text.size() && std::isspace(text[start])) {
            ++start;
        }
    }

    // Sets intersection
    std::vector<std::string> commonWords;
    for (const auto& word : narrativeWords) {
        if (exclamatoryWords.find(word) != exclamatoryWords.end()) {
            commonWords.push_back(word);
        }
    }

    // Sorting
    std::sort(commonWords.begin(), commonWords.end());

    // Result output
    std::cout << "Words found in narrative and exclamation sentences:" << std::endl;
    for (const auto& word : commonWords) {
        std::cout << word << std::endl;
    }

    return 0;
}


// She loves to walk in the park. How wonderful it is to walk in the park! Do you love to walk in the park?
