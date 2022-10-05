//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_TIME_H
#define ACTIVITYLOG_TIME_H


class Time {
public:
    Time();
    Time(unsigned int hour,unsigned int minutes,unsigned int seconds);
    Time& operator=(const Time& right);
    ~Time()=default;

private:
    unsigned int Seconds;
    unsigned int Minutes;
    unsigned int Hour;

};


#endif //ACTIVITYLOG_TIME_H
