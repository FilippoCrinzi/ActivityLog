//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Log.h"
#include "Date.h"


void Log::addActivity(const Activity& activityToAdd) {
    //std::map<Date, std::list<Activity>>::iterator itr;
    bool found = false;

    //Controllo se nel registro è già presente un attività fatta nello stesso giorno di quella che voglio inserire,
    //in tal caso aggiungo l'attività nella lista di attività del giorno
    for (auto &itr: activityRegister) {
        if (itr.first == activityToAdd.getDate()) {
            auto it = itr.second.begin();
            while (it != itr.second.end() && (it->getStart() < activityToAdd.getStart() or it->getStart()== activityToAdd.getStart()) ) {

                if (it->getStart()==activityToAdd.getStart() && it->getFinish() == activityToAdd.getFinish() && it->getDescription() == activityToAdd.getDescription()) {
                    throw std::invalid_argument("Invalid activity: the activity you are trying to add already exists.");
                }
                ++it;
            }

            itr.second.insert(it, activityToAdd);
            found = true;

        }
    }
    //Se non ho trovato altre attività fatte nello stesso giorno aggiungo nel registro un giorno con la sua lista delle attività
    if (!found) {
        std::list<Activity> NewDay;
        NewDay.push_back(activityToAdd);
        activityRegister[activityToAdd.getDate()] = NewDay;
        //activityRegister.insert(activityRegister.end(),std::make_pair(d,NewDay));

    }
}


Log::~Log() {
    activityRegister.clear();
}


const std::list<Activity> &Log::find(Date d) const{
    for (auto &itr: activityRegister) {
        if (itr.first == d)
            return itr.second;
    }
    return std::list<Activity>();
}


void Log::removeActivity(const Activity& activityToRemove) {
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
                break;
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid update: the activity you are trying to modify does not exist.");
    }
}

int Log::countActivities() {
    int count = 0;
    for (auto &itr: activityRegister) {
        count += itr.second.size();
    }
    return count;
}

void Log::updateActivity(const Activity& oldActivity, const Time& newTime, FieldToUpdate field) {
    bool found = false;

    for (auto &itr: activityRegister) {
        if (itr.first == oldActivity.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), oldActivity);
            if (it != itr.second.end()) {
                found = true;
                if (field == FieldToUpdate::Start) {
                    if (oldActivity.getFinish() < newTime) {
                        throw std::invalid_argument("Invalid activity: start time must be before finish time");
                    }
                    if (newTime == oldActivity.getFinish()) {
                        throw std::invalid_argument("Invalid activity: start time must be different from finish time");
                    }
                    it->setStart(newTime); // Modifica il tempo di inizio
                } else if (field == FieldToUpdate::Finish) {
                    if (newTime < oldActivity.getStart()) {
                        throw std::invalid_argument("Invalid activity: start time must be before finish time");
                    }
                    if (newTime == oldActivity.getStart()) {
                        throw std::invalid_argument("Invalid activity: start time must be different from finish time");
                    }
                    it->setFinish(newTime); // Modifica il tempo di fine
                } else {
                    throw std::invalid_argument(
                            "Invalid update: you're trying to modify the time but the field is incorrect.");
                }
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid update: the activity you are trying to modify does not exist.");
    }
}

void Log::updateActivity(const Activity& oldActivity, const QString& newDescription, FieldToUpdate field) {
    bool found = false;

    for (auto &itr: activityRegister) {
        if (itr.first == oldActivity.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), oldActivity);
            if (it != itr.second.end()) {
                found = true;
                if (field == FieldToUpdate::Description) {
                    it->setDescription(newDescription); // Modifica la descrizione
                } else {
                    throw std::invalid_argument(
                            "Invalid update: you're trying to modify the description but the field is incorrect.");
                }
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid update: the activity you are trying to modify does not exist.");
    }
}

void Log::updateActivity(const Activity& oldActivity, const Date& newDate, FieldToUpdate field) {
    bool found = false;

    for (auto &itr: activityRegister) {
        if (itr.first == oldActivity.getDate()) {
            auto it = std::find(itr.second.begin(), itr.second.end(), oldActivity);
            if (it != itr.second.end()) {
                found = true;
                if (field == FieldToUpdate::Date) {
                    removeActivity(oldActivity);
                    addActivity(Activity(oldActivity.getDescription(), oldActivity.getStart(), oldActivity.getFinish(),
                                         newDate));
                    break;
                } else {
                    throw std::invalid_argument(
                            "Invalid update: you're trying to modify the date but the field is incorrect.");
                }
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid update: the activity you are trying to modify does not exist.");
    }
}

