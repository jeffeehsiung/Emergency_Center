#include "headers/SensorGroup.h"
#include "SensorGroup.h"

/** SensorGroup specific methods */
void SensorGroup::addComponent(std::shared_ptr<Component> component){
    /** the component parameter is a reference to a Sensor component. 
     * the method adds the component to the vector of components 
     **/
    components.push_back(component);
}

void SensorGroup::removeComponent(std::shared_ptr<Component> component){
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

std::vector<std::shared_ptr<Component>> SensorGroup::getComponents()
{
    /** return the updated vector of components **/
    return components;
}

/** SensorGroup specific methods */
/** inline getters and setter can be overriden by derived classes 
 * the following method will check if the component is a sensor or a sensor group
 * if the component is a sensor, the method will get the id, activation time start, activation time end, location, and vendor
 * if the component is a sensor group, the method will get the id, activation time start, activation time end, location, and vendor for each sensor in the sensor group
 * each information is separated by a space
 * the method will return the information
*/
std::string SensorGroup::getId() const
{
    // return group id
    return id;
}

void SensorGroup::setActivationTime(int start, int end)
{
    // for each sensor in the sensor group, set the activation time
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setActivationTime(start, end);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setActivationTime(start, end);
            }
        }
    }
}

void SensorGroup::setActive()
{
    // for each sensor in the sensor group, set the active status
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setActive();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setActive();
            }
        }
    }
}

void SensorGroup::setNotActive()
{
    // for each sensor in the sensor group, set the not active status
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setNotActive();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setNotActive();
            }
        }
    }
}

void SensorGroup::setAlwaysActive(bool alwaysActive)
{
    // for each sensor in the sensor group, set the always active status
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setAlwaysActive(alwaysActive);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setAlwaysActive(alwaysActive);
            }
        }
    }
}

void SensorGroup::updateSoftware()
{
    // for each sensor in the sensor group, update the software
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->updateSoftware();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->updateSoftware();
            }
        }
    }
}

void SensorGroup::setLocation(const std::string& location)
{
    // for each sensor in the sensor group, set the location
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setLocation(location);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setLocation(location);
            }
        }
    }
}

void SensorGroup::setVendor(const std::string& vendor)
{
    // for each sensor in the sensor group, set the vendor
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->setVendor(vendor);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->setVendor(vendor);
            }
        }
    }
}


void SensorGroup::addStrategy(std::shared_ptr<SensorStrategy> strategy)
{
    // for each sensor in the sensor group, add the strategy
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->addStrategy(strategy);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->addStrategy(strategy);
            }
        }
    }
}

void SensorGroup::removeStrategy(std::shared_ptr<SensorStrategy> strategy)
{
    // for each sensor in the sensor group, remove the strategy
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            std::dynamic_pointer_cast<Sensor>(component)->removeStrategy(strategy);
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->removeStrategy(strategy);
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
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getComponents()){
                std::dynamic_pointer_cast<Sensor>(sensor)->executeStrategy();
            }
        }
    }
}

/** Operator overloading methods */
Component& SensorGroup::operator++(){
    // activate each sensor in the sensor group
    setActive();
    return *this;
}

Component& SensorGroup::operator--(){
    // deactivate each sensor in the sensor group
    setNotActive();
    return *this;
}
