//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_TIME_H
#define ACTIVITYLOG_TIME_H
#include "string"


class Time {
public:
    Time();
    Time(unsigned int hour,unsigned int minutes);

    unsigned int getMinutes() const;

    unsigned int getHour() const;

    Time& operator=(const Time& right);
    bool operator<(const Time& other) const;
    ~Time()=default;

private:
    unsigned int Minutes;
    unsigned int Hour;

};


#endif //ACTIVITYLOG_TIME_H
