#pragma once
#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "Sensor.h"
#include "SensorGroup.h"
#include "SensorConfig.h"

class EmergencyCenter {
private:
    static std::unique_ptr<EmergencyCenter> instance; // Singleton instance
    std::list<std::unique_ptr<Component>> components;

public:
    // Constructor & Destructor
    EmergencyCenter();
    ~EmergencyCenter();

    // Singleton related methods
    static EmergencyCenter* getInstance();
    
    // Other methods
    void addComponent(std::unique_ptr<Component> component);
    void removeComponent(Component* component);
    bool testComponent(Component* component);

    void printAllComponents();
    void activateAllComponents(int mode);
    void deactivateAllComponents(int mode);
    bool testAllComponents(int mode);
    void updateAllSoftwares();

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center);
};

#endif // EMERGENCYCENTER_H
