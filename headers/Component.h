#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory>
#include "SensorStrategy.h"

class Component {
protected:
    std::string id;
    int activationTimeStart;
    int activationTimeEnd;
    bool isActive;
    bool alwaysActive;
    int deactivationTime;
    std::string location;
    std::string vendor;
    int softwareVersion;
    std::vector<std::shared_ptr<SensorStrategy>> strategies;

public:
    // constructor and destructor
    Component() = default;
    Component(std::string id, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime): id{id}, activationTimeStart{activationTimeStart}, activationTimeEnd{activationTimeEnd}, 
    isActive{isActive}, alwaysActive{alwaysActive}, deactivationTime{deactivationTime}{}
    
    virtual ~Component() = default;

    /** inline getters and setters and can be overriden by derived classes */
    virtual std::string getId() const{
        return id;
    }

    virtual void setId(const std::string& id){
        this->id = id;
    }

    virtual int getActivationTimeStart() const{
        return activationTimeStart;
    }

    virtual int getActivationTimeEnd() const{
        return activationTimeEnd;
    }

    virtual void setActivationTime(int start, int end){
        this->activationTimeStart = start;
        this->activationTimeEnd = end;
    }

    virtual bool getIsActive() const{
        return isActive;
    }

    virtual void setActive() {
        this->isActive = true;
    }

    virtual void setNotActive() {
        this->isActive = false;
    }

    virtual bool getAlwaysActive() const{
        return alwaysActive;
    }

    virtual void setAlwaysActive(bool alwaysActiveStatus){
        this->alwaysActive = alwaysActiveStatus;
    }

    virtual int getDeactivationTime() const{
        return deactivationTime;
    }

    virtual void setDeactivationTime(int deactivation){
        this->deactivationTime = deactivation;
    }

    virtual std::string getLocation() const{
        return location;
    }

    virtual void setLocation(const std::string& location){
        this->location = location;
    }

    virtual std::string getVendor() const{
        return vendor;
    }
    /** setVendor method to be implemented by derived classes */
    virtual void setVendor(const std::string& vendor){
        this->vendor = vendor;
    }

    virtual void updateSoftware(){
        this->softwareVersion++;
    }

    virtual int getSoftwareVersion() const{
        return softwareVersion;
    }

    virtual void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy)
    {
        strategies.push_back(sensorStrategy);
    }

    virtual void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy)
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
    }

    virtual void executeStrategy() const{
        // Execute all strategies
        for (const auto& strategy : strategies) {
            strategy->executeStrategy();
        }
    }

    /** Operator overloading methods */
    friend std::ostream& operator<<(std::ostream& COUT, const Component& component) {
    // Print component details using its getter methods
        COUT << "ID: " << component.getId() << "\n"
            << "Activation time: " << component.getActivationTimeStart() << " to " << component.getActivationTimeEnd() << "\n"
            << "Is active? " << component.getIsActive() << "\n"
            << "Is always active? " << component.getAlwaysActive() << "\n"
            << "Deactivation time: " << component.getDeactivationTime() << "\n\n\n";
        return COUT;
    }

    Component& operator++(){
        this->setActive();
        return *this;
    }

    Component& operator--(){
        this->setNotActive();
        return *this;
    }

};

#endif // COMPONENT_H
