#ifndef COMPONENT_H
#define COMPONENT_H

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

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

public:
    virtual ~Component() {}

    virtual std::string getId() const = 0;
    virtual void setId(const std::string& id) = 0;

    virtual std::string getLocation() const = 0;
    virtual void setLocation(const std::string& location) = 0;

    virtual std::string getVendor() const = 0;
    virtual void setVendor(const std::string& vendor) = 0;

    virtual int getActivationTimeStart() const = 0;
    virtual int getActivationTimeEnd() const = 0;
    virtual void setActivationTime(int start, int end) = 0;

    virtual std::list<std::string> getMonitorScope() const = 0;
    virtual void setMonitorScope(const std::list<std::string>& scope) = 0;

    virtual bool getIsActive() const = 0;
    virtual void setActive() = 0;
    virtual void setNotActive() = 0;

    virtual bool getAlwaysActive() const = 0;
    virtual void setAlwaysActive(bool alwaysActiveStatus) = 0;

    virtual int getDeactivationTime() const = 0;
    virtual void setDeactivationTime(int deactivation) = 0;

    virtual void executeStrategy() = 0;
    virtual void updateSoftware() = 0;

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const Component& component);
    Component& operator++();
    Component& operator--();

};

#endif // COMPONENT_H
