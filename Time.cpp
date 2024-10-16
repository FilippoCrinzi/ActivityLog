//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Time.h"

Time::Time(int hour, int minutes) {
    validateTime(hour, minutes);
    this->hour = hour;
    this->minutes = minutes;
}

Time &Time::operator=(const Time &right) {
    if (this != &right) {              //evito la autoassegnazione
        hour = right.hour;
        minutes = right.minutes;
    }
    return *this;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getHour() const {
    return hour;
}

bool Time::operator<(const Time &other) const {
    if (hour == other.hour) {
        return minutes < other.minutes;
    }
    return hour < other.hour;
}

void Time::validateTime(int hour, int minutes) {
    if (hour >= 24 || minutes >= 60 || hour < 0 || minutes < 0) {
        throw std::invalid_argument("Invalid time: hour must be from 0 to 23 and minutes must be from 0 to 59");
    }
}

bool Time::operator==(const Time &right) const {
    if(hour == right.hour && minutes == right.minutes)
        return true;
    else
        return false;
}