#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <list>
#include <ctime>

class Component {
protected:
    std::string id;
    std::string location;
    time_t activationTimeStart;
    time_t activationTimeEnd;
    std::list<std::string> monitorScope;
    bool isActive;
    bool alwaysActive;
    time_t deactivationTime;

public:
    virtual ~Component() {}

    virtual std::string getId() const = 0;
    virtual void setId(const std::string& id) = 0;

    virtual std::string getLocation() const = 0;
    virtual void setLocation(const std::string& location) = 0;

    virtual time_t getActivationTimeStart() const = 0;
    virtual time_t getActivationTimeEnd() const = 0;
    virtual void setActivationTime(time_t start, time_t end) = 0;

    virtual std::list<std::string> getMonitorScope() const = 0;
    virtual void setMonitorScope(const std::list<std::string>& scope) = 0;

    virtual bool getIsActive() const = 0;
    virtual void setActive() = 0;
    virtual void setNotActive() = 0;

    virtual bool getAlwaysActive() const = 0;
    virtual void setAlwaysActive(bool alwaysActiveStatus) = 0;

    virtual time_t getDeactivationTime() const = 0;
    virtual void setDeactivationTime(time_t deactivation) = 0;

    virtual void executeStrategy() = 0;
    virtual void updateSoftware() = 0;
};

#endif // COMPONENT_H
