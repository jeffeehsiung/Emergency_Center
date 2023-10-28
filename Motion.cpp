#include "headers/Sensor.h"

Motion::Motion(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, int activationRange):
    Sensor(id, location, vendor, activationTimeStart, activationTimeEnd, isActive, alwaysActive, softwareVersion)
{
    // set the fabrication date
    this->activationRange = activationRange;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd << std::endl;
}

void Motion::setActivationRange(const int type)
{
    activationRange = type;
};

// int Motion::getActivationRange() {
//     return activationRange;
// };