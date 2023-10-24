#include "headers/Sensor.h"
#include "Sensor.h"


// Sensor::Sensor(std::string vn, std::string lo, time_t fd, int sv)
//     : vendor{vn}, location{lo}, fabricationDate{fd}, softwareVersion{sv}
// {
//   std::cout << "Sensor constructor 1 called with parameters " << vendor << ", " << location << ", " << fabricationDate << ", " << softwareVersion << std::endl;
// }

// constructor
Sensor::Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int fabricationDate):
    Component(id, location, vendor, activationTimeStart, activationTimeEnd, monitorScope, isActive, alwaysActive, deactivationTime, softwareVersion)
{
    // set the fabrication date
    this->fabricationDate = fabricationDate;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd << ", " << fabricationDate << std::endl;
}

void Sensor::addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy)
{
    strategies.push_back(sensorStrategy);
}
void Sensor::removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy)
{
    // find and remove the specified strategy making use of iterators
    for (auto it = strategies.begin(); it != strategies.end(); ++it) {
        if (*it == sensorStrategy) {
            strategies.erase(it);
            break;  // assuming there are no duplicate strategies
        }
    }
}
void Sensor::executeStrategy() const
{
    // Execute all strategies
    for (const auto& strategy : strategies) {
        strategy->executeStrategy();
    }
}
onst std::string getVendor() const {
    return vendor;
};

std::string getLocation() {
    return location;
};

std::string getFabrication() {
    return fabrication;
};

int getSoftwareVersion() {
    return softwareVersion;
};

// void addStrategy(SensorStrategy* sensorStrategy) {
//     strategies.push_back(sensorStrategy);
// };

// void removeStrategy(SensorStrategy* sensorStrategy) {
//     // Find and remove the specified strategy
//     for (auto it = strategies.begin(); it != strategies.end(); ++it) {
//         if (*it == sensorStrategy) {
//             strategies.erase(it);
//             break;  // Assuming there are no duplicate strategies
//         }
//     }
// };