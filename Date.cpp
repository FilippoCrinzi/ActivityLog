//
// Created by Filippo Crinzi on 05/10/22.
//

#include "Date.h"
#include <string>

Date::Date(int day, int month, int year) {
     validateDate(day, month, year);
     Day=day;
     Month=month;
     Year=year;
}


bool Date::operator==(const Date &right) const{
    if(Year == right.Year && Month == right.Month && Day == right.Day)
        return true;
    else
        return false;
}

bool Date::operator<( const Date &right) const {
    if(Year < right.Year)
        return true;
    if(Year == right.Year && Month < right.Month )
        return true;
    if(Year == right.Year && Month == right.Month && Day < right.Day )
        return true;

    return false;
}

int Date::getYear() const {
    return Year;
}

int Date::getMonth() const {
    return Month;
}

int Date::getDay() const {
    return Day;
}

void Date::validateDate(int day, int month, int year) {
    if (day > 31 || month > 12 || year < 0 || day < 0 || month < 0) {
        throw std::invalid_argument(
                "Invalid date: day must be from 1 to 31, month must be from 1 to 12 and year must be positive");
    }
    if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) {
        throw std::invalid_argument("Invalid date: month " + std::to_string(month) + " has only 30 days");
    }
    if (day == 30 && month == 2) {
        throw std::invalid_argument("Invalid date: February has only 28 or 29 days");
    }
    if (day == 29 && month == 2 && !checkLeapYear(year)) {
        throw std::invalid_argument("Invalid date: " + std::to_string(year) + " is not a leap year");
    }
}

bool Date::checkLeapYear(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}








