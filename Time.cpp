//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Time.h"

Time::Time(int hour, int minutes, int seconds) {
    Hour=hour;
    Minutes=minutes;
    Seconds=seconds;
}

Time& Time::operator=(const Time& right) {
    if(this != &right){              //evito la autoassegnazione
        Hour=right.Hour;
        Minutes=right.Minutes;
        Seconds=right.Seconds;
    }
    return * this;
}

Time::Time() {
     Hour=0;
     Minutes=0;
     Seconds=0;
}
