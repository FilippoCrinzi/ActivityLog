//
// Created by Filippo Crinzi on 05/10/22.
//

#ifndef ACTIVITYLOG_DATE_H
#define ACTIVITYLOG_DATE_H


class Date {
public:
    Date(int day, int month, int year);
    ~Date()= default;
    static bool checkLeapYear( int year);
    bool operator==(const Date& right) const;
    bool operator<(const Date& right) const;

    int getYear() const;

    int getMonth() const;

    int getDay() const;

private:
    int Year;
    int Month;
    int Day;
    static void validateDate(int day, int month, int year);
};


#endif //ACTIVITYLOG_DATE_H
