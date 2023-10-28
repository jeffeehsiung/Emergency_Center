#include "headers/Strategies/Notifications/SMS.h"
#include <iostream>

SMS::SMS(std::string receipientName, std::string receipientNumber, std::string message):NotificationStrategy(){
    this->receipientName = receipientName;
    this->receipientNumber = receipientNumber;
    this->message = message;
}

void SMS::executeStrategy() const
{
    std::cout << "SMS sent to " << receipientName << " at " << receipientNumber << ": " << message << std::endl;
}
