#include <iostream>
#include <string.h>

void Formatter(std::string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isspace(s[i]) && (ispunct(s[i+1]) && s[i+1] != '('))
        {
            s.replace(i, 2, s.substr(i+1, 1) + ' ');
        }
        if (isspace(s[i]) && s[i+1] == ')')
        {
            s.replace(i, 2, s.substr(i, 1) + ' ');
        }
        if (s[i] == '(' && isspace(s[i+1]))
        {
            s.replace(i, 2, ' ' + s.substr(i, 1));
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
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
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    Formatter(input);

    std::cout << "The longest word: " << input << std::endl;
    return 0;
}

// Пример   текста ,  где ( есть   ошибки ) и ,лишние   пробелы.