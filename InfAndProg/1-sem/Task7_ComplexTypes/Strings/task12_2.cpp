#include <iostream>
#include <string.h>

std::string FindLongest(std::string s)
{
    int longest = 0;
    int tempLong = 0;
    std::string longestString, tempString;
    for (int i = 0; i < s.length(); i++)
    {
        // Finding words length
        if (!(ispunct(s[i]) || isspace(s[i])))
        {
            tempString += s[i];
            tempLong++;
        }
        else
        {
            // Finding the biggest length
            if (tempLong > longest)
            {
                longest = tempLong;
                longestString = tempString;
            }

            // Variables reset
            tempLong = 0;
            tempString.clear();
        }
    }

    return longestString;
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string longestString = FindLongest(input);

    std::cout << "The longest word: " << longestString << std::endl;
    return 0;
}

// Это пример ввода. Самое длинное слово, которое будет выведено, расположено здесь: йцукенгшщзхъфыв, а все остальные меньше него.