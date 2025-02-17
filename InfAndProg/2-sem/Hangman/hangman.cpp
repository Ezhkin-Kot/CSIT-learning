#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

const std::vector<std::string> WORDS = {"programming", "developer", "vector", "docker", "kubernetes",
                              "linux", "deployment", "exception", "legacy", "algorithm"};
const int MAX_TRIES = 6;
const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void drawHangman(int mistakes) {
    std::vector<std::string> hangman = {
        "  +---+",
        "  |   |",
        "      |",
        "      |",
        "      |",
        "      |",
        "========="
    };
    if (mistakes > 0) hangman[2] = "  O   |";
    if (mistakes > 1) hangman[3] = "  |   |";
    if (mistakes > 2) hangman[3] = " /|   |";
    if (mistakes > 3) hangman[3] = " /|\\  |";
    if (mistakes > 4) hangman[4] = " /    |";
    if (mistakes > 5) hangman[4] = " / \\  |";

    for (const auto& line : hangman) {
        std::cout << line << std::endl;
    }
}

int main() {
    srand(time(NULL));
    std::string word = WORDS[rand() % WORDS.size()];
    std::string guessed(word.size(), '_');
    std::string alphabet = ALPHABET;
    int mistakes = 0;

    while (mistakes < MAX_TRIES && guessed != word) {
        std::cout << "\nGuessed word: " << guessed << std::endl;
        std::cout << "Remaining letters: " << alphabet << std::endl;
        drawHangman(mistakes);

        std::cout << "\nEnter a letter or try to guess the word: ";
        std::string input;
        std::cin >> input;

        if (input.length() > 1) {
            if (input == word) {
                std::cout << "Win! You guessed the word: " << word << std::endl;
                return 0;
            } else {
                std::cout << "Wrong word. Game over." << std::endl;
                return 0;
            }
        } else {
            char letter = input[0];
            size_t pos = word.find(letter);
            if (pos != std::string::npos) {
                for (size_t i = 0; i < word.size(); i++) {
                    if (word[i] == letter) {
                        guessed[i] = letter;
                    }
                }
                alphabet.erase(remove(alphabet.begin(), alphabet.end(), letter), alphabet.end());
            } else {
                std::cout << "There is no such letter." << std::endl;
                mistakes++;
            }
        }
    }

    if (guessed == word) {
        std::cout << "Win! You guessed the word: " << word << std::endl;
    } else {
        drawHangman(mistakes);
        std::cout << "Game over. Guessed word: " << word << std::endl;
    }

    return 0;
}
