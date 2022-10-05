//
// Created by Filippo Crinzi on 05/10/22.
//

#ifndef ACTIVITYLOG_DATE_H
#define ACTIVITYLOG_DATE_H


class Date {
public:
    Date(unsigned int day,unsigned int month,unsigned int year);
    ~Date()= default;
    bool checkLeapYear();
    bool operator==(const Date& right);
private:
    unsigned int Year;
    unsigned int Month;
    unsigned int Day;
};


#endif //ACTIVITYLOG_DATE_H
