#include "headers/Sensor.h"

Motion::Motion(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int activationRange):
    Sensor(id, location, vendor, activationTimeStart, activationTimeEnd, isActive, alwaysActive, deactivationTime, softwareVersion)
{
    // set the fabrication date
    this->activationRange = type;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd << ", " << fabricationDate << std::endl;
}

void Motion::setActivationRange(const int activationRange)
{
    activationRange = activationRange;
};

int Motion::getActivationRange() {
    return activationRange;
};