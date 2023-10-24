#include "Component.h"
#include <memory> // for std::shared_ptr

class SensorGroup: public Component{
protected:
    std::vector<Component&> components;
public:
    virtual void addSensor(Component& component);
    virtual void removeSensor(Component& component);
    virtual void getSensors();
};