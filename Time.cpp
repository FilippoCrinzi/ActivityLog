//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Time.h"

Time::Time(unsigned int hour,unsigned int minutes) {
    Hour=hour;
    Minutes=minutes;
}

Time& Time::operator=(const Time& right) {
    if(this != &right){              //evito la autoassegnazione
        Hour=right.Hour;
        Minutes=right.Minutes;
    }
    return * this;
}

Time::Time() {
     Hour=0;
     Minutes=0;
}

unsigned int Time::getMinutes() const {
    return Minutes;
}

unsigned int Time::getHour() const {
    return Hour;
}

