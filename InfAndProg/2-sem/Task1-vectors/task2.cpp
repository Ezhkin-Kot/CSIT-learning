#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> setVector()
{
    int n;
    std::vector<int> vec;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // Vector filling
    std::cout << "Enter vector elements separated by space: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }

    return vec;
}

void printVector(std::vector<int> vec)
{
    for(const int & iter : vec)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
}

bool isEven(int num)
{
    return num % 2 == 0;
}

void removeEven(std::vector<int>& vec)
{
    vec.erase(std::remove_if(vec.begin(), vec.end(), isEven), vec.end());
}

bool isMultipleOfThree(int num)
{
    return num % 3 == 0;
}

void replaceWithMin(std::vector<int>& vec)
{
    int min = *min_element(vec.begin(), vec.end());

    for(int & iter : vec)
    {
        if (isMultipleOfThree(iter))
        {
            iter = min;
        }
    }
}

std::vector<int> processVectors(std::vector<int>& vec1, std::vector<int>& vec2)
{
    removeEven(vec1);

    replaceWithMin(vec2);

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    // Merging vectors
    std::vector<int> vec12;
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(vec12));

    vec12.erase(std::unique(vec12.begin(), vec12.end()), vec12.end());

    return vec12;
}

int main()
{
    std::vector<int> vec1 = setVector();
    std::vector<int> vec2 = setVector();

    printVector(vec1);
    printVector(vec2);

    std::vector<int> processedVec = processVectors(vec1, vec2);

    std::cout << "Result: ";
    printVector(processedVec);

    return 0;
}
