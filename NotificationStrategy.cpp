#include "headers/Strategies/NotificationStrategy.h"

void SMS::executeStrategy() const
{
    std::cout << "SMS sent to " << receipientName << " at " << receipientNumber << ": " << message << std::endl;
}

void Email::executeStrategy() const
{
    std::cout << "Email sent to " << receipientName << " at " << receipientEmail << ": " << message << std::endl;
}