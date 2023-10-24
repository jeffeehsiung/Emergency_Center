#include "headers/Sensor.h"
#include "Sensor.h"

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
    /** the sensorStrategy paramter is a shared pointer to the abstract class SensorStrategy.
     * the method removes the SensorStreatgy from the vector list
     * the method utilize the std::find function from the algorithm library
     * reference: https://unstop.com/blog/find-in-vector-cpp
     * reference: https://en.cppreference.com/w/cpp/algorithm/find
    */
    auto it = std::find(strategies.begin(), strategies.end(), sensorStrategy);
    if (it != strategies.end()) {
        strategies.erase(it);
    }
    // // find and remove the specified strategy making use of iterators
    // for (auto it = strategies.begin(); it != strategies.end(); ++it) {
    //     if (*it == sensorStrategy) {
    //         strategies.erase(it);
    //         break;  // assuming there are no duplicate strategies
    //     }
    // }
}
void Sensor::executeStrategy() const
{
    // Execute all strategies
    for (const auto& strategy : strategies) {
        strategy->executeStrategy();
    }
}

std::string getFabrication() {
    return fabricationDate;
}

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