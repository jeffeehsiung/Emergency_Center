#include "headers/Sensor.h"

Gas::Gas(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, std::string type):
    Sensor(id, location, vendor, activationTimeStart, activationTimeEnd, isActive, alwaysActive, deactivationTime, softwareVersion)
{
    // set the fabrication date
    this->gasType = type;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd  << std::endl;
}

void Gas::setGasType(const std::string& type)
{
    gasType = type;
};

// std::string Gas::getGasType() {
//     return gasType;
// };