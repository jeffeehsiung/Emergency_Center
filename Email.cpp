#include "headers/Strategies/Actions/Email.h"
#include <iostream>

void Email::executeStrategy() const
{
    std::cout << "Email sent to " << receipientName << " at " << receipientEmail << ": " << message << std::endl;
}