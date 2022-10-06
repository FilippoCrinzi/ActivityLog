//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Log.h"
#include "Date.h"

void Log::AddActivity(Date& d,Activity a) {
    std::map<Date, std::list<Activity>>::iterator itr;
    bool find=false;
    for(itr = Register.begin(); itr != Register.end(); itr++){
        if(itr->first == d)
        itr->second.push_back(a);
        find=true;
    }
    if(!find){
       // Register.insert(std::make_pair(d, new std:: list<Activity>));
    }
    }

void Log::ReadActivity(Date giorno) {
}

Log::~Log() {
   Register.clear();
}
