#include "headers/Strategies/Actions/LeafAlarm.h"
#include <iostream>

void LeafAlarm::executeStrategy() const
{
    std::cout << "activating and sound the " << leafAlarm << " alarm" << std::endl;   
}
