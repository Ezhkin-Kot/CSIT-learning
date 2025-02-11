#include <iostream>
#include <string.h>

void Formatter(std::string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isspace(s[i]) && (ispunct(s[i+1]) && s[i+1] != '('))
        {
            s.replace(i, 2, s.substr(i+1, 1) + ' '); // Remove extra spaces with puncts
        }
        if (isspace(s[i]) && s[i+1] == ')')
        {
            s.replace(i, 2, s.substr(i, 1) + ' '); // Remove extra spaces with open brackets
        }
        if (s[i] == '(' && isspace(s[i+1]))
        {
            s.replace(i, 2, ' ' + s.substr(i, 1)); // Remove extra spaces with close brackets
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (!isspace(s[i]) && s[i] != '(' && s[i+1] == '(') {
            s.insert(i + 1, " "); // Add spaces before open brackets
            i++;
        }
        if (s[i] == ')' && !isspace(s[i+1]) && !ispunct(s[i+1]) && s[i+1] != ')') {
            s.insert(i + 1, " "); // Add spaces after close brackets
            i++;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        // Remove all extra spaces
        if (isspace(s[i]) && isspace(s[i+1]))
        {
            s.erase(i, 1);
            i--;
        }
    }
}

int main()
{
    std::string input;
    std::cout << "Enter text: ";
    std::getline(std::cin, input);

    Formatter(input);

    std::cout << "Correct text: " << input << std::endl;
    return 0;
}

// Это(пример)текста ,  где ( есть   ошибки ), и ,лишние   пробелы .