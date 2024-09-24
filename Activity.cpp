//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Activity.h"

Activity::Activity(QString description, Time start, Time finish)
: Description(description), Start(start), Finish(finish) { }

QString const Activity::getDescription()const {
    return Description;
}

const Time &Activity::getFinish() const {
    return Finish;
}

const Time &Activity::getStart() const {
    return Start;
}
