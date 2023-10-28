#pragma once

#ifndef SENSORGROUP_H
#define SENSORGROUP_H
#include "Component.h"
#include "Sensor.h"

class SensorGroup: public Component{
protected:
    std::vector<std::shared_ptr<Component>> components;
public:
    // constructor
    SensorGroup(std::string id): Component(id){}
    // destructor
    ~SensorGroup() = default;
    
    /** SensorGroup specific methods */
    // function to add a sensor to the vector of sensors
    virtual void addComponent(std::shared_ptr<Component> component);
    // function to remove a sensor from the vector of sensors
    virtual void removeComponent(std::shared_ptr<Component> component);
    // function to get and return the vector of sensors
    virtual std::vector<std::shared_ptr<Component>> getSensors();
    // execute the strategy for the entire sensor group
    virtual void executeStrategy() const override;
    /** Operator overloading methods overriden from base class */
    virtual Component& operator++();
    virtual Component& operator--();
    /** overload << operator for output stream */
    friend std::ostream& operator<<(std::ostream& os, const SensorGroup& sensorGroup);
};
#endif 