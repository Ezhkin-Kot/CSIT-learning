#include <iostream>
#include <fstream>
#include <vector>

std::ifstream inputFile("input.txt");
std::ofstream outputFile("output.txt");

std::vector<std::vector<int>> readArray()
{
    if (!inputFile)
    {
        std::cerr << "File not opened" << std::endl;
        return std::vector<std::vector<int>>();
    }

    int n;
    inputFile >> n;
    std::vector<std::vector<int>> array(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> array[i][j];
        }
    }
    inputFile.close();
    return array;
}

void writeArray(const std::vector<std::vector<int>> &array)
{
    outputFile << array.size() << std::endl;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            outputFile << array[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();
    std::cout << "File written" << std::endl;
}

void quickSort(std::vector<int>& column, int left, int right)
{
    if (left >= right) return;
    int pivot = column[(left + right) / 2];
    int i = left, j = right;
    while (i <= j)
    {
        while (column[i] < pivot) i++;
        while (column[j] > pivot) j--;
        if (i <= j)
        {
            std::swap(column[i], column[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(column, left, j);
    if (i < right) quickSort(column, i, right);
}

void columnsQuickSort(std::vector<std::vector<int>> &array)
{
    for (int j = 0; j < array.size(); j++)
    {
        // Collect column elements
        std::vector<int> column(array.size());
        for (int i = 0; i < array.size(); i++)
        {
            column[i] = array[i][j];
        }

        quickSort(column, 0, array.size() - 1);

        // Writing sorted elements
        for (int i = 0; i < array.size(); i++)
        {
            array[i][j] = column[i];
        }
    }
}

void shellSort(std::vector<int>& column, bool isEven)
{
    int n = column.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = column[i];
            int j;
            for (j = i; j >= gap && ((isEven && column[j - gap] > temp) ||
                (!isEven && column[j - gap] < temp)); j -= gap)
            {
                column[j] = column[j - gap];
            }
            column[j] = temp;
        }
    }
}

void columnsShellSort(std::vector<std::vector<int>>& array)
{
    for (int j = 0; j < array.size(); j++)
    {
        // Collect column elements
        std::vector<int> column(array.size());
        for (int i = 0; i < array.size(); i++)
        {
            column[i] = array[i][j];
        }

        shellSort(column, j % 2);

        // Writing sorted elements
        for (int i = 0; i < array.size(); i++)
        {
            array[i][j] = column[i];
        }
    }
}

void selectionSort(std::vector<int>& diagonal)
{
    int n = diagonal.size();
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;
        // Find max element
        for (int j = i + 1; j < n; j++)
        {
            if (diagonal[j] > diagonal[maxIdx])
            {
                maxIdx = j;
            }
        }
        std::swap(diagonal[i], diagonal[maxIdx]);
    }
}

void diagonalsSelectionSort(std::vector<std::vector<int>>& array)
{
    // Main and upper diagonals sorting
    for (int d = 0; d < array.size(); d++)
    {
        std::vector<int> diagonal;

        // Collect diagonal elements
        for (int i = 0, j = d; j < array.size(); i++, j++)
        {
            diagonal.push_back(array[i][j]);
        }

        selectionSort(diagonal);

        // Write sorted elements
        int index = 0;
        for (int i = 0, j = d; j < array.size(); i++, j++)
        {
            array[i][j] = diagonal[index++];
        }
    }

    // Lower diagonals sorting
    for (int d = 1; d < array.size(); d++)
    {
        std::vector<int> diagonal;

        // Collect diagonal elements
        for (int i = d, j = 0; i < array.size(); i++, j++)
        {
            diagonal.push_back(array[i][j]);
        }

        selectionSort(diagonal);

        // Write sorted elements
        int index = 0;
        for (int i = d, j = 0; i < array.size(); i++, j++)
        {
            array[i][j] = diagonal[index++];
        }
    }
}

void sortArraySelector(std::vector<std::vector<int>> &array)
{
    char choice;
    std::cout << "Sorting methods:" << std::endl;
    std::cout << "1. Quick sort columns" << std::endl;
    std::cout << "2. Shell sort columns" << std::endl;
    std::cout << "3. Selection sort diagonals" << std::endl;
    std::cout << "Choose sorting method (1, 2, 3): ";
    std::cin >> choice;

    switch (choice)
    {
        case '1':
            columnsQuickSort(array);
            std::cout << "Array columns sorted" << std::endl;
            break;
        case '2':
            columnsShellSort(array);
            std::cout << "Array columns sorted" << std::endl;
            break;
        case '3':
            diagonalsSelectionSort(array);
            std::cout << "Array diagonals sorted" << std::endl;
            break;
        default:
            std::cerr << "Invalid choice" << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> array = readArray();

    sortArraySelector(array);

    writeArray(array);
    return 0;
}
