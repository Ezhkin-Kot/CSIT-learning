#include <iostream>
using namespace std;

int DaysCalculator(int day, int month, int year) {
    const int DAYS_COUNT[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // an array with all counts of days in each month

    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) { // Checking if month February and a year is a leap
        if (DAYS_COUNT[month - 1] + 1 < day || day <= 0) { // Errors catching
            return -1;
        }
        if (year < 0) {
            return -2;
        }
        return DAYS_COUNT[1] + 1 - day;
    }
    if (DAYS_COUNT[month - 1] < day || day <= 0) { // Errors catching
        return -1;
    }
    if (year < 0) {
        return -2;
    }
    return DAYS_COUNT[month - 1] - day;
}
string MonthName(int month) {
    switch (month) {
        case 1: return "января";
        case 2: return "февраля";
        case 3: return "марта";
        case 4: return "апреля";
        case 5: return "мая";
        case 6: return "июня";
        case 7: return "июля";
        case 8: return "августа";
        case 9: return "сентября";
        case 10: return "октября";
        case 11: return "ноября";
        case 12: return "декабря";
        default: return "?";
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int day, month, year;
    const int DayErrorCode = -1, YearErrorCode = -2; // Error codes

    cout << "Введите дату (ДД ММ ГГГГ): ";
    cin >> day >> month >> year; // getting the date

    int DaysLeft = DaysCalculator(day, month, year); // calculating how many days are left until the end of the month
    // exceptions catching
    if (DaysLeft == DayErrorCode) {
        cout << "неправильный день" << endl;
        return -1;
    }
    if (DaysLeft == YearErrorCode) {
        cout << "неправильный год" << endl;
        return -2;
    }


    string strMonth = MonthName(month); // transform integer type of month into a word
    if (strMonth == "?") { // exception catching
        cout << "неправильный месяц" << endl;
        return -3;
    }
    if (DaysLeft < -2 || DaysLeft > 31) {
        cout << "неизвестная ошибка" << endl;
        return 0;
    }

    // output
    cout << day << " " << strMonth << " " << year << " года" << endl;
    cout << "Дней до конца месяца: " << DaysLeft << endl;

    return 1;
}