//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_ACTIVITY_H
#define ACTIVITYLOG_ACTIVITY_H

#include <string>
#include "Time.h"
#include <QString>
#include "Date.h"


class Activity {
public:
    Activity(QString description, Time start, Time finish, Date date);

    ~Activity() = default;

    QString getDescription() const;

    const Time &getFinish() const;

    const Time &getStart() const;

    const Date &getDate() const;

    bool operator==(const Activity &right);

    void setStart(const Time &newStart);

    void setFinish(const Time &newFinish);

    void setDescription(const QString &newDescription);

private:
    QString description;
    Time finish;
    Time start;
    Date date;

    void validateActivity(Time start, Time finish);

};


#endif //ACTIVITYLOG_ACTIVITY_H
