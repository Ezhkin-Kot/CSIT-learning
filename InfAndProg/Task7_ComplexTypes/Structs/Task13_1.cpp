#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

struct Hotel {
    std::string firstName, lastName, surname;
    std::string arrivalDate, departureDate;

    std::string GetFullName()
    {
        std::string fullName = lastName + " " + firstName + " " + surname;
        return fullName;
    }

    void SetFullName(std::string fullName)
    {
        std::stringstream ss(fullName);
        ss >> lastName >> firstName >> surname;
    }

    // Calculate days in hotel
    int calculateDays() {
        std::tm arrival = {};
        std::tm departure = {};

        // Convert date string into std::tm
        if (!parseDate(arrivalDate, arrival) || !parseDate(departureDate, departure)) {
            std::cerr << "Error: invalid date format. Expected YYYY-MM-DD." << std::endl;
            return -1;
        }

        // Convert std::tm into time in secnds
        std::time_t arrivalTime = std::mktime(&arrival);
        std::time_t departureTime = std::mktime(&departure);

        if (departureTime < arrivalTime) {
            std::cerr << "Error: departure time is before arrival time." << std::endl;
            return -1;
        }

        // Difference between days
        const int SECONDS_IN_DAY = 24 * 60 * 60;
        return (departureTime - arrivalTime) / SECONDS_IN_DAY;
    }

    private:
    // Convert string into std::tm
    static bool parseDate(const std::string& date, std::tm& tm) {
        // Expected format: YYYY.MM.DD or YYYY-MM-DD
        int year, month, day;
        char delimiter1, delimiter2;

        std::istringstream iss(date);
        if (!(iss >> year >> delimiter1 >> month >> delimiter2 >> day) ||
            (delimiter1 != '-' && delimiter1 != '.') || (delimiter2 != '-' && delimiter2 != '.') || !isValidDate(year, month, day)) {
            return false;
        }

        tm.tm_year = year - 1900;  // std::tm: years from 1900
        tm.tm_mon = month - 1;    // std::tm: months from 0 to 11
        tm.tm_mday = day;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        return true;
    }

    // Check date correctness
    static bool isValidDate(int year, int month, int day) {
        if (year < 1900 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        // Count of days in month
        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Check leap year
        bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

        int maxDays = month == 2 && isLeapYear ? 29 : daysInMonth[month - 1];
        return day <= maxDays;
    }
};

// Set tourist data
Hotel inputHotelData() {
    Hotel hotel;
    std::cout << "Enter full name of tourist divide by spaces: ";
    std::string input;
    std::getline(std::cin, input);
    hotel.SetFullName(input);

    std::cout << "Enter arrival date (in format YYYY-MM-DD): ";
    std::getline(std::cin, hotel.arrivalDate);

    std::cout << "Enter departure date (in format YYYY-MM-DD): ";
    std::getline(std::cin, hotel.departureDate);

    return hotel;
}

int main() {
    Hotel hotel = inputHotelData();

    int days = hotel.calculateDays();
    if (days != -1) {
        std::cout << "Tourist " << hotel.GetFullName() << " will spend " << days << " days in the hotel." << std::endl;
    }

    return 0;
}