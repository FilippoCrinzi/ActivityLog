//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_ACTIVITY_H
#define ACTIVITYLOG_ACTIVITY_H

#include <string>
#include "Time.h"
#include <QString>


class Activity {
public:
    Activity(QString description, Time start, Time finish);
    ~Activity()=default;
    QString const getDescription()const;

    const Time &getFinish() const;

    const Time &getStart() const;

private:
 QString Description;
 Time Finish;
 Time Start;

};


#endif //ACTIVITYLOG_ACTIVITY_H
