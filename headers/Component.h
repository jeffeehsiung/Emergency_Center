#ifndef COMPONENT_H
#define COMPONENT_H

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory>

class Component {
protected:
    std::string id;
    std::string location;
    std::string vendor;
    int activationTimeStart;
    int activationTimeEnd;
    std::list<std::string> monitorScope;
    bool isActive;
    bool alwaysActive;
    int deactivationTime;
    int softwareVersion;

public:
    virtual ~Component() {}

    // make the getId method constant
    virtual std::string getId() const{
        return id;
    }
    virtual void setId(const std::string& id) const{
        this->id = id;
    }

    virtual std::string getLocation() const{
        return location;
    }
    virtual void setLocation(const std::string& location) const{
        this->location = location;
    }

    virtual std::string getVendor() const{
        return vendor;
    }
    virtual void setVendor(const std::string& vendor) const{
        this->vendor = vendor;
    }

    virtual int getActivationTimeStart() const{
        return activationTimeStart;
    }
    virtual int getActivationTimeEnd() const{
        return activationTimeEnd;
    }
    virtual void setActivationTime(int start, int end) const{
        this->activationTimeStart = start;
        this->activationTimeEnd = end;
    }

    virtual std::list<std::string> getMonitorScope() const{
        return monitorScope;
    }
    virtual void setMonitorScope(const std::list<std::string>& scope) const{
        this->monitorScope = scope;
    }

    virtual bool getIsActive() const{
        return isActive;
    }
    virtual void setActive() const{
        this->isActive = true;
    }
    virtual void setNotActive() const{
        this->isActive = false;
    }

    virtual bool getAlwaysActive() const{
        return alwaysActive;
    }
    virtual void setAlwaysActive(bool alwaysActiveStatus) const{
        this->alwaysActive = alwaysActiveStatus;
    }

    virtual int getDeactivationTime() const{
        return deactivationTime;
    }
    virtual void setDeactivationTime(int deactivation) const{
        this->deactivationTime = deactivation;
    }
    virtual void updateSoftware() const{
        this->softwareVersion++;
    }
    virtual int getSoftwareVersion() const{
        return softwareVersion;
    }
    virtual void executeStrategy() = 0;

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const std::list<std::string>& list) {
        COUT << "[";
        for (const auto& item : list) {
            COUT << item;
            if (&item != &list.back()) COUT << ", ";
        }
        COUT << "]";
        return COUT;
    }

    friend std::ostream& operator<<(std::ostream& COUT, const Component& component) {
        // Print component details using its getter methods
        COUT << "ID: " << component.getId() << "\n"
            << "Location: " << component.getLocation() << "\n"
            << "Vendor: " << component.getVendor() << "\n"
            << "Activation time: " << component.getActivationTimeStart() << " to " << component.getActivationTimeEnd() << "\n"
            << "Monitor scope: " << component.getMonitorScope() << "\n"
            << "Is active? " << component.getIsActive() << "\n"
            << "Is always active? " << component.getAlwaysActive() << "\n"
            << "Deactivation time: " << component.getDeactivationTime() << "\n\n\n";
        return COUT;
    }

    Component& operator++() {
        this->setActive();
        return *this;
    }

    Component& operator--() {
        this->setNotActive();
    return *this;
    }

};

#endif // COMPONENT_H
