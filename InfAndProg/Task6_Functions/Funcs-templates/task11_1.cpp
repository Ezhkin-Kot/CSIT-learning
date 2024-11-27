#include <iostream>
#include <sstream>

template<typename T>
T **SetArray(int *size)
{
    std::cout << "Enter size of array: ";
    std::cin >> *size;
    // Checking correctness of input
    if (!std::cin || *size < 1)
    {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
    }

    // Memory allocation
    T **array = new T *[*size];
    for (int i = 0; i < *size; i++)
    {
        array[i] = new T[*size];
    }

    // Choosing random or manual array setting
    char choice;
    std::cout << "Random or manual array setting? Type \"R\" to random or \"M\" to manual: ";
    std::cin >> choice;
    switch (choice)
    {
        case 'R':
        {
            srand(time(NULL)); // Initialize random generator
            char typeChoice;
            std::cout << "What type of elements you want? Type \"I\" to integer, \"F\" to floating point number or \"S\" to symbols: ";
            std::cin >> typeChoice;
            switch (typeChoice)
            {
                case 'I':
                {
                    // Randomise elements of array
                    for (int i = 0; i < *size; i++, std::cout << std::endl)
                    {
                        for (int j = 0; j < *size; j++)
                        {
                            array[i][j] = rand() % 100;
                            std::cout << array[i][j] << "\t";
                        }
                    }
                    break;
                }
                case 'F':
                {
                    for (int i = 0; i < *size; i++, std::cout << std::endl)
                    {
                        for (int j = 0; j < *size; j++)
                        {
                            array[i][j] = rand() % 10000 / 100.0;
                            std::cout << array[i][j] << "\t";
                            array[i][j] = (int)array[i][j] == array[i][j] ? array[i][j] + 0.01 : array[i][j];
                        }
                    }
                    break;
                }
                case 'S':
                {
                    for (int i = 0; i < *size; i++, std::cout << std::endl)
                    {
                        for (int j = 0; j < *size; j++)
                        {
                            array[i][j] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 36];
                            std::cout << array[i][j] << "\t";
                        }
                    }
                    break;
                }
                default:
                {
                    std::cerr << "Invalid type" << std::endl;
                    return array;
                }
            }
            break;
        }
        case 'M':
        {
            std::cout << "Enter array: \n";
            for (int i = 0; i < *size; i++)
            {
                for (int j = 0; j < *size; j++)
                {
                    std::cin >> array[i][j]; // Manual setting elements of array
                }
            }
            break;
        }
        default:
        {
            std::cerr << "Invalid type" << std::endl;
            break;
        }
    }

    std::cout << std::endl;
    return array;
}

template<typename T>
void replaceRows(T **array, const int *size)
{
    T temp = 0; // Intermediate value of element

    // Replacing rows
    for (int i = 0; i < *size / 2; i++)
    {
        for (int j = 0; j < *size; j++)
        {
            temp = array[i][j];
            array[i][j] = array[*size - i - 1][j];
            array[*size - i - 1][j] = temp;
        }
    }
}

template<typename T>
void printArray(T **array, const int *size)
{
    // Output an array
    for (int i = 0; i < *size; i++, std::cout << std::endl)
    {
        for (int j = 0; j < *size; j++)
        {
            std::cout << array[i][j] << "\t";
        }
    }
    std::cout << std::endl;
}

template<typename T>
void deleteArray(T **array, const int *size)
{
    // Memory cleaning
    for (int i = 0; i < *size; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}

int main()
{
    int size1 = 0;
    int **array1 = SetArray<int>(&size1);
    replaceRows(array1, &size1);
    printArray(array1, &size1);

    int size2 = 0;
    double **array2 = SetArray<double>(&size2);
    replaceRows(array2, &size2);
    printArray(array2, &size2);

    int size3 = 0;
    char **array3 = SetArray<char>(&size3);
    replaceRows(array3, &size3);
    printArray(array3, &size3);

    deleteArray(array1, &size1);
    deleteArray(array2, &size2);
    deleteArray(array3, &size3);
}
