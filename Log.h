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
    Log(){};
    void AddActivity(const Date d,Activity a);
    void ReadActivity(Date giorno);
    ~Log();
private:
    std::map <Date,std::list<Activity>> Register ;
};


#endif //ACTIVITYLOG_LOG_H
