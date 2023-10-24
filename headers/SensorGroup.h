#include "Component.h"

class SensorGroup: public Component{
    protected:
    std::vector<Component*> components;
    public:
    virtual void addStrategy(Component* component);
    virtual void removeStrategy(Component* component);
};