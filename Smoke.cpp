#include "headers/Sensor.h"

Smoke::Smoke(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int threshold):
    Sensor(id, location, vendor, activationTimeStart, activationTimeEnd, isActive, alwaysActive, deactivationTime, softwareVersion)
{
    // set the fabrication date
    this->threshold = threshold;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd  << std::endl;
}

void Smoke::setThreshold(const int type)
{
    threshold = type;
};

// int Smoke::getThreshold() {
//     return threshold;
// };