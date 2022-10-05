//
// Created by Filippo Crinzi on 05/10/22.
//

#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
     Day=day;
     Month=month;
     Year=year;
}

bool Date::checkLeapYear() {
    bool temp=false;
    if (Year % 4 == 0) {
        if (Year % 100 == 0) {
            if (Year % 400 == 0) temp=true;
            else temp=false;
        } else temp=true;
    } else temp=false;
    return temp;
}

bool Date::operator==(const Date &right) {
    if(Year==right.Year && Month==right.Month && Day==right.Day){
        return true;
    }
    else
    return false;
}




