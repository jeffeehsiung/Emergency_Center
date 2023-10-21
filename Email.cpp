#include "Email.h"

void Email::executeStrategy(string receiver) const
{
    std::cout << "Email sent to " << receiver << "\n" << std::endl;
}
