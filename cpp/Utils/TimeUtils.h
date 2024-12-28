#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <sstream>
#include <iomanip>

struct Time {
    int hour;
    int minute;
    int second;

    Time(int hour = 0, int minute = 0, int second = 0) {
        this->hour = (hour >= 0 && hour < 24) ? hour : 0;
        this->minute = (minute >= 0 && minute < 60) ? minute : 0;
        this->second = (second >= 0 && second < 60) ? second : 0;
    }

    void incrementTime() {
        second++;
        if (second >= 60) {
            minute++;
            second = 0;
        }
        if (minute >= 60) {
            hour++;
            minute = 0;
        }
        if (hour >= 24) {
            hour = 0;
        }
    }

    bool operator==(const Time& other) const {
        return hour==other.hour && minute==other.minute && second==other.second;
    }

    bool operator<(const Time& other) const {
        if (hour != other.hour) return hour < other.hour;
        if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }

    bool operator>(const Time& other) const {
        if (hour != other.hour) return hour > other.hour;
        if (minute != other.minute) return minute > other.minute;
        return second > other.second;   
    }

    bool operator<=(const Time& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const Time& other) const {
        return *this > other || *this == other;
    }


    std::string toString() const {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hour << ":"
            << std::setw(2) << std::setfill('0') << minute << ":"
            << std::setw(2) << std::setfill('0') << second;
        return oss.str();
    }
};

struct DateTime {
    int year;
    int month;
    int day;
    Time time;

    DateTime(int year = 2024, int month = 12, int day = 21, Time time = Time())
        : year(year), month(month), day(day), time(time) {
        if (month < 1 || month > 12) month = 1;
        if (day < 1 || day > 31) day = 1;
    }

    void incrementDateTime() {
        time.incrementTime();
        if (time.hour == 0 && time.minute == 0 && time.second == 0) {
            day++;
            if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
                day = 1; month++;
            } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                day = 1; month++;
            } else if (month == 2 && day > 28) { 
                day = 1; month++;
            }
            if (month > 12) {
                month = 1; year++;
            }
        }
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << year << "-"
            << std::setw(2) << std::setfill('0') << month << "-"
            << std::setw(2) << std::setfill('0') << day << " "
            << time.toString();
        return oss.str();
    }
};

#endif
