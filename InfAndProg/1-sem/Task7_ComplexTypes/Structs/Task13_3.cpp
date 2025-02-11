#include <iostream>
#include <time.h>
#include <regex>
#include <iomanip>

struct Time {
    int hours, minutes, seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    bool isValid = true;

    void setTime(std::string inputTime) {
        std::regex timeRegex(R"(\b([01][0-9]|2[0-4])\:([0-5][0-9])\:([0-5][0-9])\b)");

        if (!std::regex_match(inputTime, timeRegex)) {
            std::cerr << "Invalid time format. Expected HH:MM:SS" << std::endl;
            isValid = false;
            return;
        }

        hours = stoi(inputTime.substr(0, 2));
        minutes = stoi(inputTime.substr(3, 2));
        seconds = stoi(inputTime.substr(6, 2));
    }

    // Total seconds count
    int getTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Total minutes count
    double getTotalMinutes() const {
        return hours * 60 + minutes + seconds / 60.0;
    }

    // Total hours count
    double getTotalHours() const {
        return hours + minutes / 60.0 + seconds / 3600.0;
    }

    // Time after N seconds
    Time getTimeAfterSeconds(int additionalSeconds){
        Time result;
        int totalSeconds = getTotalSeconds() + additionalSeconds;
        
        // If additionalSeconds is negative
        while (totalSeconds < 0) {
            totalSeconds += 24 * 3600;
        }
        
        // Convert to 24-h format
        totalSeconds %= (24 * 3600);
        
        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;
        
        return result;
    }

    // Difference between first and second times
    static Time timeDifference(const Time& t1, const Time& t2) {
        Time result;
        int totalSeconds1 = t1.getTotalSeconds();
        int totalSeconds2 = t2.getTotalSeconds();
        
        // If second time is less than first
        if (totalSeconds2 < totalSeconds1) {
            totalSeconds2 += 24 * 3600;
        }
        
        int diffSeconds = totalSeconds2 - totalSeconds1;
        result.hours = diffSeconds / 3600;
        result.minutes = (diffSeconds % 3600) / 60;
        result.seconds = diffSeconds % 60;
        
        return result;
    }

    // Output in format HH:MM:SS
    void print() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds;
    }
};

int main() {
    Time t1, t2;
    std::string input;
    
    std::cout << "Enter first time (HH:MM:SS): ";
    std::cin >> input;
    t1.setTime(input);
    
    std::cout << "Enter second time (HH:MM:SS): ";
    std::cin >> input;
    t2.setTime(input);
    
    if (!t1.isValid || !t2.isValid) {
        std::cerr << "Error: invalid time" << std::endl;
        return 1;
    }
    
    std::cout << "Difference between times: ";
    Time diff = Time::timeDifference(t1, t2);
    diff.print();
    std::cout << std::endl;
    
    int seconds;
    std::cout << "Enter seconds to add to the first time: ";
    std::cin >> seconds;
    
    Time futureTime = t1.getTimeAfterSeconds(seconds);
    std::cout << "Time after " << seconds << " seconds: ";
    futureTime.print();
    std::cout << std::endl;
    
    return 0;
}
