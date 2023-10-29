#include "headers/Sensors/Gas.h"

Gas::Gas(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive,  
int softwareVersion, std::string type, int capacity):
    Sensor(id, location, vendor, activationTimeStart, activationTimeEnd, isActive, alwaysActive, softwareVersion)
{
    // set the fabrication date
    this->gasType = type;
    this->amount = capacity;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd  << std::endl;
}

void Gas::setAmount(const int type)
{
    amount = type;
};

void Gas::setGasType(const std::string& type)
{
    gasType = type;
};