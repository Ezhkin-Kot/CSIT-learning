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

bool operator < (const Employee &firstEmployee, const Employee &secondEmployee){ // Redored operator <
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
            if (employees[i+gap] < employees[i])
            {
                std::swap(employees[i], employees[i+gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    std::vector<Employee> employees = readEmployeeFile();

    combSort(employees);

    writeEmployeeFile(employees);
    return 0;
}
