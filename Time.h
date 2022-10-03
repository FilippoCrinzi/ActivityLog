//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_TIME_H
#define ACTIVITYLOG_TIME_H


class Time {
public:
    Time();
    Time(int hour,int minutes, int seconds);
    Time& operator=(const Time& right);
private:
    int Seconds;
    int Minutes;
    int Hour;

};


#endif //ACTIVITYLOG_TIME_H
