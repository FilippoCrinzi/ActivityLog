//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Log.h"
#include "Date.h"


void Log::AddActivity(Date d, Activity const &a) {
    //std::map<Date, std::list<Activity>>::iterator itr;
    bool find=false;
    std::list<Activity> NewDay;
    //Controllo se nel registro è già presente un attività fatta nello stesso giorno di quella che voglio inserire,
    //in tal caso aggiungo l'attività nella lista di attività del giorno
    for(auto & itr : Register){
        if(itr.first == d){
            auto it = itr.second.begin();
            while (it != itr.second.end() && it->getStart() < a.getStart()) {
                ++it;
            }

            itr.second.insert(it,a);
           find=true;
           std::printf("\nprova");
        }
    }
    //Se non ho trovato altre attività fatte nello stesso giorno aggiungo nel registro un giorno con la sua lista delle attività
    if(!find){
        //NewDay.clear();
        NewDay.push_back(a);
        //NewDay.push_back(a);
        Register[d] = NewDay ;
        //Register.insert(Register.end(),std::make_pair(d,NewDay));
        std::printf("\nprova2");
    }
    }

void Log::ReadActivity(Date giorno) {

}

Log::~Log() {
   Register.clear();
}



std::list<Activity> Log::find(Date d) {
    for(auto & itr : Register) {
        if (itr.first == d)
            return itr.second;
    }
        return std::list<Activity>();
}
