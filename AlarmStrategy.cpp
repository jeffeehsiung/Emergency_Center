#include "headers/Strategies/AlarmStrategy.h"

void GroupAlarm::executeStrategy() const
{
    std::cout << "activating and sound the " << groupAlarm << " alarm" << std::endl;
}

void LeafAlarm::executeStrategy() const
{
    std::cout << "activating and sound the " << leafAlarm << " alarm" << std::endl;   
}
