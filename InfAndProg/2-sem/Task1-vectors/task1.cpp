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

int countMinElems(std::vector<int> vec)
{
    // Finding min element
    int minElem = *min_element(vec.begin(), vec.end());

    int count = 0;

    for(const int & iter : vec)
    {
        // Calculating number of min elements
        if (iter == minElem)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    std::vector<int> vec = setVector();

    printVector(vec);

    int count = countMinElems(vec);
    std::cout << "Number of minimal elements: " << count << std::endl;

    return 0;
}
