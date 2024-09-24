//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Time.h"

Time::Time(int hour,int minutes) {
    validateTime(hour, minutes);
    Hour=hour;
    Minutes=minutes;
}

Time& Time::operator=(const Time& right){
    if(this != &right){              //evito la autoassegnazione
        Hour=right.Hour;
        Minutes=right.Minutes;
    }
    return * this;
}

int Time::getMinutes() const {
    return Minutes;
}

int Time::getHour() const {
    return Hour;
}

bool Time::operator<(const Time& other) const {
    if (Hour == other.Hour) {
        return Minutes < other.Minutes;
    }
    return Hour < other.Hour;
}

void Time::validateTime(int hour, int minutes) {
    if (hour >= 24 || minutes >= 60 || hour < 0 || minutes < 0) {
        throw std::invalid_argument("Invalid time: hour must be from 0 to 23 and minutes must be from 0 to 59");
    }
}
