#include "GroupAlarm.h"
#include <iostream>

void GroupAlarm::executeStrategy() const
{
    std::cout << "activating and sound the " << groupAlarm << " alarm" << std::endl;
}
