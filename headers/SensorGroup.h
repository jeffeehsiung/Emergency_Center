#include "Component.h"

class SensorGroup: public Component{
protected:
    std::vector<std::shared_ptr<Component>> components;
public:
    // constructor
    SensorGroup();
    SensorGroup(std::string id,int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime);
    // destructor
    ~SensorGroup() = default;
    // function to add a sensor to the vector of sensors
    virtual void addSensor(std::shared_ptr<Component> component);
    // function to remove a sensor from the vector of sensors
    virtual void removeSensor(std::shared_ptr<Component> component);
    // function to get and return the vector of sensors
    virtual std::vector<std::shared_ptr<Component>> getSensors();
    // execute the strategy for the entire sensor group
    virtual void executeStrategy() const override;

};