//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_TIME_H
#define ACTIVITYLOG_TIME_H

#include "string"


class Time {
public:
    Time(int hour, int minutes);

    ~Time() = default;

    int getMinutes() const;

    int getHour() const;

    Time &operator=(const Time &right);

    bool operator<(const Time &other) const;

    bool operator==(const Time &right) const;


private:
    int minutes;
    int hour;

    void validateTime(int hour, int minutes);

};


#endif //ACTIVITYLOG_TIME_H
