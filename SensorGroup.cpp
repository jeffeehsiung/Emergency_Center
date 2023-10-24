#include "headers/SensorGroup.h"
#include "SensorGroup.h"

SensorGroup::SensorGroup(){
    // The 'components' vector is automatically initialized as an empty vector.
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

void SensorGroup::executeStrategy() const{
    // execute the strategy for each sensor in the sensor group
    for (const auto& component : components) {
        component->executeStrategy();
    }
}
