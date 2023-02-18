//
// Created by Filippo Crinzi on 03/10/22.
//

#include "Activity.h"

Activity::Activity(std::string description, Time start, Time finish) {
      Description=description;
      Finish=finish;
      Start=start;
}

std::string const Activity::getDescription()const {
    return Description;
}
