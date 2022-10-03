//
// Created by Filippo Crinzi on 03/10/22.
//

#ifndef ACTIVITYLOG_LOG_H
#define ACTIVITYLOG_LOG_H
#include <map>
#include <list>
#include "Activity.h"

class Log {
public:
    Log(){};
    void AddActivity(Activity a);
    void ReadActivity(int giorno);
private:
    std::map <int ,std::list<Activity>> Register ;
// TODO: implementare una classe Day, la chiave del registro deve essere di tipo Day non int

};


#endif //ACTIVITYLOG_LOG_H
