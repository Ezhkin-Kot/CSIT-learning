#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

std::string readFile(const std::string fileName)
{
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << fileName << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    return line;
}

void writeFile(const std::string fileName, const std::string line)
{
    std::ofstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << fileName << std::endl;
        return;
    }

    file << line;
}

std::string CorrectDates(std::string text)
{
    // Регулярное выражение для проверки формата "dd.mm.yyyy"
    std::regex dateRegex1(R"(\b(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.(\d{4})\b)");
    // Регулярное выражение для проверки формата "dd month yyyy"
    std::regex dateRegex2(R"(\b(0[1-9]|[12][0-9]|3[01]) (January|February|March|April|May|June|July|August|September|October|November|December) (\d{4})\b)", std::regex::icase);

    std::vector <std::string> tempSentences;
    std::vector <std::string> correctSentences;
    std::string result;

    // Split text with dots
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '.')
        {
            tempSentences.push_back(text.substr(0, i + 1));
            text.erase(0, i + 1);
            i = 0;
        }
    }

    // Find correct dates
    for (int i = 0; i < tempSentences.size(); i++)
    {
        if (i + 2 < tempSentences.size())
        {
            if (std::regex_search((tempSentences[i] + tempSentences[i + 1] + tempSentences[i + 2]), dateRegex1))
            {
                correctSentences.push_back(tempSentences[i] + tempSentences[i + 1] + tempSentences[i + 2]);
                if (std::regex_search(tempSentences[i], dateRegex2))
                {
                    i++;
                }
            }
        }
        if (std::regex_search(tempSentences[i], dateRegex2))
        {
            correctSentences.push_back(tempSentences[i]);
        }
    }

    // Build correct text
    for (auto s : correctSentences)
    {
        if (result.find(s) == std::string::npos)
        {
            result += s;
        }
    }

    return result;
}

int main()
{
    std::string dates = readFile("dates.txt");
    std::string correctDates = CorrectDates(dates);
    writeFile("CorrectDates.txt", correctDates);
    return 0;
}