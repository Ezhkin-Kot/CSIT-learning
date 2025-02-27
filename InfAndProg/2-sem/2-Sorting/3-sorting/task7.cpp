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

int main()
{
    std::vector<Employee> employees = readEmployeeFile();

    quickSort(employees, 0, employees.size() - 1);

    writeEmployeeFile(employees);
    return 0;
}
