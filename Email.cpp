#include "headers/Strategies/Notifications/Email.h"
#include <iostream>

Email::Email(std::string receipientName, std::string receipientEmail, std::string message):
    NotificationStrategy()
{
    this->receipientName = receipientName;
    this->receipientEmail = receipientEmail;
    this->message = message;
}

void Email::executeStrategy() const
{
    std::cout << "Email sent to " << receipientName << " at " << receipientEmail << ": " << message << std::endl;
}