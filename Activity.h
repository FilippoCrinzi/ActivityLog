//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_ACTIVITY_H
#define ACTIVITYLOG_ACTIVITY_H

#include <string>
#include "Time.h"


class Activity {
public:
    Activity(std::string description, Time start, Time finish);
    ~Activity()=default;
    std::string const getDescription()const ;
private:
 std::string Description;
 Time Finish;
 Time Start;



};


#endif //ACTIVITYLOG_ACTIVITY_H
