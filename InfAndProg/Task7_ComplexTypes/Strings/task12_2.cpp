#include <iostream>
#include <string.h>

std::string FindLongest(std::string s)
{
    int longest = 0;
    int tempLong = 0;
    std::string longestString, tempString;
    for (int i = 0; i < s.length(); i++)
    {
        if (!(ispunct(s[i]) || isspace(s[i])))
        {
            tempString += s[i];
            tempLong++;
        }
        else
        {
            if (tempLong > longest)
            {
                longest = tempLong;
                longestString = tempString;
            }

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