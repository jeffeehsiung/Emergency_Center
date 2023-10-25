#include "headers/Strategies/EmergencyStrategy.h"

void CentralDispatch::executeStrategy() const
{
    // call the central dispatch
    std::cout << "Calling the KULeuven central dispatch for evacuation\n" << std::endl;
}

void FireBrigade::executeStrategy() const
{
    // call the fire brigade. no specificatoin needded
    std::cout << "Calling the fire brigade.\n" << std::endl;
}

void Police::executeStrategy() const
{
    // call the police
    std::cout << "Calling the police for a quick warning.\n" << std::endl;
}

void Security::executeStrategy() const
{
    // call the security
    std::cout << "Notifying the KULeuven security team \n" << std::endl;
}