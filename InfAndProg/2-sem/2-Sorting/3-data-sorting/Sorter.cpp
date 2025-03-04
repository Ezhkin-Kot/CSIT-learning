#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

std::ifstream inputFile("employees.txt");
std::ofstream outputFile("output.txt");

struct Date
{
    int day, month, year;
};

struct Employee
{
    std::string surname;
    std::string position;
    Date dateOfBirth{};
    int experience = 0;
    double salary = 0.0;
};

Date StringToDate(std::string str)
{
    Date date{};

    std::string temp = str.substr(0, 4); // Year
    date.year = atoi(temp.c_str());

    temp = str.substr(5, 2); // Month
    date.month = atoi(temp.c_str());

    temp = str.substr(8, 2); // Day
    date.day = atoi(temp.c_str());

    return date;
}

std::vector<Employee> readEmployeeFile()
{
    if (!inputFile.is_open())
    {
        std::cerr << "File not opened" << std::endl;
        return std::vector<Employee>{};
    }

    std::vector<Employee> employees;
    Employee newEmployee;
    while(inputFile.peek() != EOF)
    {
        inputFile >> newEmployee.surname;
        inputFile >> newEmployee.position;

        std::string tmp; // Date of birth
        inputFile >> tmp;
        newEmployee.dateOfBirth = StringToDate(tmp);

        inputFile >> newEmployee.experience;
        inputFile >> newEmployee.salary;

        employees.push_back(newEmployee);
    }
    inputFile.close();
    return employees;
}

void writeEmployeeFile(const std::vector<Employee> &employees)
{
    // Header
    outputFile << std::left << std::setw(20) << "Surname" << std::setw(20) << "Position"
               << std::setw(20) << "Date of birth" << std::setw(20) << "Experience" << std::setw(20) << "Salary" << std::endl;
    outputFile << std::string(90, '_') << std::endl;

    // Table
    for (const auto& e : employees) {
        outputFile << std::left << std::setw(20) << e.surname << std::setw(20) << e.position
           << std::setw(20) << std::to_string(e.dateOfBirth.year) + "-" +
                                (e.dateOfBirth.month < 10 ? "0" : "") + std::to_string(e.dateOfBirth.month) + "-" +
                                (e.dateOfBirth.day < 10 ? "0" : "") + std::to_string(e.dateOfBirth.day)
           << std::setw(20) << e.experience
           << std::setw(20) << std::fixed << std::setprecision(2) << e.salary << std::endl;
    }
    std::cout << "File written" << std::endl;
    outputFile.close();
}

void quickSort(std::vector<Employee> &employees, int left, int right)
{
    if (left >= right) return;
    double pivot = employees[(left + right) / 2].salary;
    int i = left, j = right;
    while (i <= j)
    {
        while (employees[i].salary < pivot)
        {
            i++;
        }
        while (employees[j].salary > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(employees[i], employees[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(employees, left, j);
    if (i < right) quickSort(employees, i, right);
}

// First employee less than second
bool yearExpComparer (const Employee &firstEmployee, const Employee &secondEmployee){
    if (firstEmployee.dateOfBirth.year < secondEmployee.dateOfBirth.year) return true;
    if (firstEmployee.dateOfBirth.year == secondEmployee.dateOfBirth.year && firstEmployee.experience < secondEmployee.experience) return true;
    return false;
}

void combSort(std::vector<Employee> &employees)
{
    int gap = employees.size();
    const double reducingFactor = 1.247;
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        gap = static_cast<int>(gap / reducingFactor);
        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;
        for (int i = 0; i < employees.size() - gap; i++)
        {
            if (yearExpComparer(employees[i+gap], employees[i]))
            {
                std::swap(employees[i], employees[i+gap]);
                swapped = true;
            }
        }
    }
}

// Positions sorting priority
std::unordered_map<std::string, int> positionPriority = {
    {"Director", 1}, {"Manager", 2}, {"Engineer", 3}, {"Analyst", 4},
    {"Programmer", 5}, {"Designer", 6}, {"Marketer", 7}, {"Tester", 8}, {"Administrator", 9}
}; 

// First employee less than second
bool posExpSalComparer (const Employee &firstEmployee, const Employee &secondEmployee){
    int firstPosition = positionPriority[firstEmployee.position];
    int secondPosition = positionPriority[secondEmployee.position];

    if (firstPosition > secondPosition) return true;
    if (firstPosition == secondPosition && firstEmployee.experience < secondEmployee.experience) return true;
    if (firstPosition == secondPosition && firstEmployee.experience == secondEmployee.experience &&
        firstEmployee.salary < secondEmployee.salary) return true;
    return false;
}

void bubbleSort(std::vector<Employee> &employees)
{
    bool swapped;
    for (size_t i = 0; i < employees.size() - 1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < employees.size() - i - 1; j++)
        {

            if (posExpSalComparer(employees[j+1], employees[j]))
            {
                std::swap(employees[j], employees[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void sortSelector(std::vector<Employee> &employees)
{
    char choice;
    std::cout << "Sorting methods:" << std::endl;
    std::cout << "1. Quick sort employee sales" << std::endl;
    std::cout << "2. Comb sort employee birth year, then experience" << std::endl;
    std::cout << "3. Bubble sort employee position, then experience, then salary" << std::endl;
    std::cout << "Choose sorting method (1, 2, 3): ";
    std::cin >> choice;

    switch (choice)
    {
        case '1':
            quickSort(employees, 0, employees.size() - 1);
            std::cout << "Employees sorted by salary" << std::endl;
            break;
        case '2':
            combSort(employees);
            std::cout << "Employees sorted by birth year, then by experience" << std::endl;
            break;
        case '3':
            bubbleSort(employees);
            std::cout << "Employees sorted by position, then by experience and then by salary" << std::endl;
            break;
        default:
            std::cerr << "Invalid choice" << std::endl;
    }
}

int main()
{
    std::vector<Employee> employees = readEmployeeFile();

    sortSelector(employees); // Choice sorting method

    writeEmployeeFile(employees);
    return 0;
}
