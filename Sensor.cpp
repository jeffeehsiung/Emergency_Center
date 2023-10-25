#include "headers/Sensor.h"

// constructor
Sensor::Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, time_t fabricationDate):
    Component(id, activationTimeStart, activationTimeEnd, monitorScope, isActive, alwaysActive, deactivationTime)
{
    // set the fabrication date
    this->fabricationDate = fabricationDate;
    this->location = location;
    this->softwareVersion = softwareVersion;
    std::cout << "Sensor constructor 1 called with parameters " << id << ", " << location << ", " << vendor << ", " << activationTimeStart << ", " << activationTimeEnd << ", " << fabricationDate << std::endl;
}

std::string Sensor::getLocation() const{
    return location;
}
void Sensor::setLocation(const std::string& location){
    this->location = location;
}

std::string Sensor::getVendor() const{
    return vendor;
}
void Sensor::setVendor(const std::string& vendor){
    this->vendor = vendor;
}

void Sensor::updateSoftware(){
    this->softwareVersion++;
}

int Sensor::getSoftwareVersion() const{
    return softwareVersion;
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
