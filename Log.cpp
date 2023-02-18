//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Log.h"
#include "Date.h"

void Log::AddActivity(Date d, Activity a) {
    //std::map<Date, std::list<Activity>>::iterator itr;
    bool find=false;
    //Controllo se nel registro è già presente un attività fatta nello stesso giorno di quella che voglio inserire,
    //in tal caso aggiungo l'attività nella lista di attività del giorno
    for(auto itr = Register.begin(); itr != Register.end(); itr++){
        if(itr->first == d)
        itr->second.push_back(a);
        find=true;
    }
    //Se non ho trovato altre attività fatte nello stesso giorno aggiungo nel registro un giorno con la sua lista delle attività
    if(!find){
        std::list< Activity> NewDay;
        NewDay.push_back(a);
        Register.insert(std::make_pair(d,NewDay));

    }
    }

void Log::ReadActivity(Date giorno) {

}

Log::~Log() {
   Register.clear();
}



std::list<Activity> Log::find(Date d) {
    for(auto itr = Register.begin(); itr != Register.end(); itr++){
        if(itr->first == d)
            return itr->second;
        return std::list<Activity>();
    }
}
