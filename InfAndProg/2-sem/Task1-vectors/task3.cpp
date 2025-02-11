#include <iostream>
#include <numeric>
#include <functional>
#include <list>

std::list<double> setList()
{
    int n;
    std::list<double> list;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // List filling
    std::cout << "Enter vector elements separated by space: ";
    for (int i = 0; i < n; i++)
    {
        double x;
        std::cin >> x;
        list.push_back(x);
    }

    return list;
}

void printList(std::list<double> list)
{
    for(const double & iter : list)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
}

double calculateVariance(std::list<double> list)
{
    double mean = std::accumulate(list.begin(), list.end(), 0.0) / list.size();

    // Calculating sum
    double sum = 0.0;
    for (double x : list) {
        sum += (x - mean) * (x - mean);
    }

    // Calculating and returning variance
    return sum / (list.size() - 1);
}

int main()
{
    std::list<double> list = setList();

    printList(list);

    double variance = calculateVariance(list);
    std::cout << "Variance = " << variance << std::endl;

    return 0;
}
