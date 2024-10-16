//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Log.h"
#include "Date.h"


void Log::addActivity(const Activity &activityToAdd) {
    //std::map<Date, std::list<Activity>>::iterator itr;
    bool found = false;

    //Controllo se nel registro è già presente un attività fatta nello stesso giorno di quella che voglio inserire,
    //in tal caso aggiungo l'attività nella lista di attività del giorno
    for (auto &itr: activityRegister) {
        if (itr.first == activityToAdd.getDate()) {
            auto it = itr.second.begin();
            while (it != itr.second.end() && it->getStart() < activityToAdd.getStart()) {
                ++it;
            }

            itr.second.insert(it, activityToAdd);
            found = true;
            std::printf("\nprova");
        }
    }
    //Se non ho trovato altre attività fatte nello stesso giorno aggiungo nel registro un giorno con la sua lista delle attività
    if (!found) {
        std::list<Activity> NewDay;
        NewDay.push_back(activityToAdd);
        activityRegister[activityToAdd.getDate()] = NewDay;
        //activityRegister.insert(activityRegister.end(),std::make_pair(d,NewDay));
        std::printf("\nprova2");
    }
}


Log::~Log() {
    activityRegister.clear();
}


std::list<Activity> Log::find(Date d) {
    for (auto &itr: activityRegister) {
        if (itr.first == d)
            return itr.second;
    }
    return std::list<Activity>();
}


void Log::removeActivity(const Activity &activityToRemove) {
    bool found = false;

    for (auto &itr: activityRegister) {
        if (itr.first == activityToRemove.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), activityToRemove);
            if (it != itr.second.end()) {
                itr.second.erase(it);
                found = true;
                if (itr.second.empty()) {
                    activityRegister.erase(itr.first);
                }
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Stai cercando di eliminare un'attività che non esiste");
    }
}

int Log::countActivities() {
    int count = 0;
    for (auto &itr: activityRegister) {
        count += itr.second.size();
    }
    return count;
}

void Log::updateActivity(const Activity &oldActivity, const Time &newTime, FieldToUpdate field) {

    for (auto &itr: activityRegister) {
        if (itr.first == oldActivity.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), oldActivity);
            if (it != itr.second.end()) {
                if (field == FieldToUpdate::Start) {
                    it->setStart(newTime); // Modifica il tempo di inizio
                } else if (field == FieldToUpdate::Finish) {
                    it->setFinish(newTime); // Modifica il tempo di fine
                } else {
                    throw std::invalid_argument(
                            "stai cercando di modificare il tempo ma non hai specificato correttamente il campo");
                }
            } else {
                throw std::invalid_argument("stai cercando di modificare un'attività che non esiste");
            }
        }
    }
}

void Log::updateActivity(const Activity &oldActivity, const QString &newDescription, FieldToUpdate field) {

    for (auto &itr: activityRegister) {
        if (itr.first == oldActivity.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), oldActivity);
            if (it != itr.second.end()) {
                if (field == FieldToUpdate::Description) {
                    it->setDescription(newDescription); // Modifica la descrizione
                } else {
                    throw std::invalid_argument(
                            "stai cercando di modificare la descrizione ma non hai specificato correttamente il campo");
                }
            } else {
                throw std::invalid_argument("stai cercando di modificare un'attività che non esiste");
            }
        }
    }
}

void Log::updateActivity(const Activity &oldActivity, const Date &newDate, FieldToUpdate field) {
    if (field == FieldToUpdate::Date) {
        removeActivity(oldActivity);
        addActivity(Activity(oldActivity.getDescription(), oldActivity.getStart(), oldActivity.getFinish(), newDate));
    } else {
        throw std::invalid_argument(
                "stai cercando di modificare la data ma non hai specificato correttamente il campo");
    }
}

