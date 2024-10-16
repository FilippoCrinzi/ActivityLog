//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_LOG_H
#define ACTIVITYLOG_LOG_H

#include <map>
#include <list>
#include "Activity.h"
#include "Date.h"

class Log {
public:
    Log() = default;

    void addActivity(const Activity &a);

    std::list<Activity> find(Date d);

    enum class FieldToUpdate {
        Start, Finish, Description, Date
    };

    void updateActivity(const Activity &oldActivity, const Time &newTime, FieldToUpdate field);

    void updateActivity(const Activity &oldActivity, const QString &newDescription, FieldToUpdate field);

    void updateActivity(const Activity &oldActivity, const Date &newDate, FieldToUpdate field);

    void removeActivity(const Activity &a);

    int countActivities();


    ~Log();

private:
    std::map<Date, std::list<Activity>> activityRegister;
};


#endif //ACTIVITYLOG_LOG_H
