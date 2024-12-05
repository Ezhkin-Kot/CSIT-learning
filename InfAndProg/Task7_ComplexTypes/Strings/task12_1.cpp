#include <iostream>
#include <string.h>

std::string RemoveDigits(std::string* s)
{
    for (int i = 0; i < (*s).length();)
    {
        if (isdigit((*s)[i]))
        {
            (*s).erase(i, 1); // Erase all digits
        }
        else
        {
            i++; // Step
        }
    }

    return *s;
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    RemoveDigits(&input);

    std::cout << "String without digits: " << input << std::endl;
    return 0;
}

// Это при12413мер ст1234роки, со13дер5жащий бук0вы и 1234567890цифры. 