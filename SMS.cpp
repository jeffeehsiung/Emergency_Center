#include "SMS.h"
#include <iostream>

void SMS::executeStrategy() const
{
    std::cout << "SMS sent to " << receipientName << " at " << receipientNumber << ": " << message << std::endl;
}
