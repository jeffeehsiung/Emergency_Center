#include "headers/SensorGroup.h"
#include "SensorGroup.h"

/** SensorGroup specific methods */
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
    // for each sensor in the sensor group, get the id
    std::string id = "";
    for (const auto& component : components) {
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            id += std::dynamic_pointer_cast<Sensor>(component)->getId() + " ";
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                id += std::dynamic_pointer_cast<Sensor>(sensor)->getId() + " ";
            }
        }
    }
    return id;
}

int SensorGroup::getActivationTimeStart() const
{
    // for each sensor in the sensor group, get the activation time start
    int activationTimeStart = 0;
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, get the activation time start
        // if the component is a sensor group, get the activation time start for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            activationTimeStart += std::dynamic_pointer_cast<Sensor>(component)->getActivationTimeStart();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, get the activation time start
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                activationTimeStart += std::dynamic_pointer_cast<Sensor>(sensor)->getActivationTimeStart();
            }
        }
    }
}

int SensorGroup::getActivationTimeEnd() const
{
    // for each sensor in the sensor group, get the activation time end
    int activationTimeEnd = 0;
    for (const auto& component : components) {
        // check if the component is a sensor or a sensor group
        // if the component is a sensor, get the activation time end
        // if the component is a sensor group, get the activation time end for each sensor in the sensor group
        if (std::dynamic_pointer_cast<Sensor>(component) != nullptr){
            activationTimeEnd += std::dynamic_pointer_cast<Sensor>(component)->getActivationTimeEnd();
        }
        else if (std::dynamic_pointer_cast<SensorGroup>(component) != nullptr){
            // for each sensor in the sensor group, get the activation time end
            for (const auto& sensor : std::dynamic_pointer_cast<SensorGroup>(component)->getSensors()){
                activationTimeEnd += std::dynamic_pointer_cast<Sensor>(sensor)->getActivationTimeEnd();
            }
        }
    }
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
