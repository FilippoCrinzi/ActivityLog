//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Activity.h"

Activity::Activity(QString description, Time start, Time finish, Date date)
        : description(description), start(start), finish(finish), date(date) {
    validateActivity(start, finish);
}

QString Activity::getDescription() const {
    return description;
}

const Time &Activity::getFinish() const {
    return finish;
}

const Time &Activity::getStart() const {
    return start;
}

const Date &Activity::getDate() const {
    return date;
}

bool Activity::operator==(const Activity &right) {
    if (description == right.description && start == right.start && finish == right.finish && date == right.date) {
        return true;
    } else
        return false;
}

void Activity::validateActivity(Time start, Time finish) {
    if (finish < start) {
        throw std::invalid_argument("Invalid activity: start time must be before finish time");
    }
    if (start == finish) {
        throw std::invalid_argument("Invalid activity: start time must be different from finish time");
    }
}

void Activity::setStart(const Time &newStart) {
    validateActivity(newStart, finish);
    start = newStart;

}

void Activity::setFinish(const Time &newFinish) {
    validateActivity(start, newFinish);
    finish = newFinish;
}

void Activity::setDescription(const QString &newDescription) {
    description = newDescription;
}
