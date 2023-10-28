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
    virtual void addSensor(std::shared_ptr<Component> component);
    // function to remove a sensor from the vector of sensors
    virtual void removeSensor(std::shared_ptr<Component> component);
    // function to get and return the vector of sensors
    virtual std::vector<std::shared_ptr<Component>> getSensors();
    
    /** inline getters and setter can be overriden by derived classes */
    virtual std::string getId() const override;
    virtual int getActivationTimeStart() const override;
    virtual int getActivationTimeEnd() const override;
    virtual void setActivationTime(int start, int end) override;
    virtual bool getIsActive() const override;
    virtual void setActive() override;
    virtual void setNotActive() override;
    virtual bool getAlwaysActive() const override;
    virtual void setAlwaysActive(bool alwaysActive) override;
    virtual int getDeactivationTime() const override;
    virtual void setDeactivationTime(int deactivationTime) override;
    virtual std::string getLocation() const override;
    virtual void setLocation(const std::string &location) override;
    virtual std::string getVendor() const override;
    virtual void setVendor(const std::string &vendor) override;
    virtual void updateSoftware() override;
    virtual int getSoftwareVersion() const override;
    virtual void addStrategy(std::shared_ptr<SensorStrategy> strategy) override;
    virtual void removeStrategy(std::shared_ptr<SensorStrategy> strategy) override;
    virtual void executeStrategy() const override;
    /** Operator overloading methods overriden from base class */
    virtual Component& operator++() override;
    virtual Component& operator--() override;
};
#endif 