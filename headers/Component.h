#ifndef COMPONENT_H
#define COMPONENT_H

#include "headers/SensorStrategy.h"

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
    // // vector list of sensor strategies
    // std::vector<std::shared_ptr<SensorStrategy>> strategies;

public:
    // constructor and destructor
    Component(){}
    Component(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion);
    
    virtual ~Component();

    // make the getId method constant
    virtual std::string getId() const;

    virtual void setId(const std::string& id);

    virtual std::string getLocation() const;

    virtual void setLocation(const std::string& location);

    virtual std::string getVendor() const;

    virtual void setVendor(const std::string& vendor);

    virtual int getActivationTimeStart() const;

    virtual int getActivationTimeEnd() const;

    virtual void setActivationTime(int start, int end);

    virtual std::list<std::string> getMonitorScope() const;

    virtual void setMonitorScope(const std::list<std::string>& scope);

    virtual bool getIsActive() const;

    virtual void setActive();

    virtual void setNotActive();

    virtual bool getAlwaysActive() const;

    virtual void setAlwaysActive(bool alwaysActiveStatus);

    virtual int getDeactivationTime() const; 

    virtual void setDeactivationTime(int deactivation);

    virtual void updateSoftware();

    virtual int getSoftwareVersion() const;

    // to be implemented by derived classes
    virtual void executeStrategy() const = 0;

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const std::list<std::string>& list);

    friend std::ostream& operator<<(std::ostream& COUT, const Component& component);

    Component& operator++();

    Component& operator--();

};

#endif // COMPONENT_H
