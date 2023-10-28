#include "headers/SensorGroup.h"
#include "SensorGroup.h"

SensorGroup::SensorGroup(std::string id, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime):
    Component(id, activationTimeStart, activationTimeEnd, isActive, alwaysActive, deactivationTime)
{
    
}

void SensorGroup::addSensor(std::shared_ptr<Component> component){
    /** the component parameter is a reference to a Sensor component. 
     * the method adds the component to the vector of components 
     **/
    components.push_back(component);
}

void SensorGroup::removeSensor(std::shared_ptr<Component> component){
    /** the component paramter is a shared pointer to the sensor component.
     * the method removes the component from the vector list
     * the method utilize the std::find function from the algorithm library
     * reference: https://unstop.com/blog/find-in-vector-cpp
     * reference: https://en.cppreference.com/w/cpp/algorithm/find
    */
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end()) {
        components.erase(it);
    }
}

std::vector<std::shared_ptr<Component>> SensorGroup::getSensors()
{
    /** return the updated vector of components **/
    return components;
}


// each sensor in the sensor group may have different locations, vendors, and strategies
std::string SensorGroup::getLocation() const
{
    // for each sensor in the sensor group, get the location
    std::string location = "";
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, get the location
        // if the component is a sensor group, get the location for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            location += std::dynamic_pointer_cast<Sensor>(component)->getLocation() + " ";
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, get the location
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                location += std::dynamic_pointer_cast<Sensor>(sensor)->getLocation() + " ";
            }
        }
    }
}

// each sensor in the sensor group may have different locations, vendors, and strategies
void SensorGroup::setLocation(const std::string &location)
{
    // for each sensor in the sensor group, set the location
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, set the location
        // if the component is a sensor group, set the location for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setLocation(location);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, set the location
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setLocation(location);
            }
        }
    }
}

std::string SensorGroup::getVendor() const
{
    // for each sensor in the sensor group, get the vendor
    std::string vendor = "";
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, get the vendor
        // if the component is a sensor group, get the vendor for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            vendor += std::dynamic_pointer_cast<Sensor>(component)->getVendor() + " ";
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, get the vendor
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                vendor += std::dynamic_pointer_cast<Sensor>(sensor)->getVendor() + " ";
            }
        }
    }
}

void SensorGroup::setVendor(const std::string &vendor)
{
    // for each sensor in the sensor group, set the vendor
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, set the vendor
        // if the component is a sensor group, set the vendor for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setVendor(vendor);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, set the vendor
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setVendor(vendor);
            }
        }
    }
}

void SensorGroup::executeStrategy() const{
    // execute the strategy for each sensor in the sensor group
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, execute the strategy
        // if the component is a sensor group, execute the strategy for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->executeStrategy();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, execute the strategy
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                std::dynamic_pointer_cast<Sensor>(sensor)->executeStrategy();
            }
        }
    }
}
