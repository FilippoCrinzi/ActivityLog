//
// Created by Filippo Crinzi on 05/10/22.
//

#include "Date.h"
#include <string>

Date::Date(int day, int month, int year) {
     validateDate(day, month, year);
     this->day=day;
     this->month=month;
     this->year=year;
}


bool Date::operator==(const Date &right) const{
    if(year == right.year && month == right.month && day == right.day)
        return true;
    else
        return false;
}

bool Date::operator<( const Date &right) const {
    if(year < right.year)
        return true;
    if(year == right.year && month < right.month )
        return true;
    if(year == right.year && month == right.month && day < right.day )
        return true;

    return false;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
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








