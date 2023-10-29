#pragma once
#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "Sensor.h"
#include "SensorGroup.h"
#include "SensorConfig.h"

class EmergencyCenter {
private:
    static std::unique_ptr<EmergencyCenter> instance; // Singleton instance
    std::vector<std::shared_ptr<Component>> components;

public:
    // Constructor & Destructor
    EmergencyCenter();
    virtual ~EmergencyCenter();

    // Singleton related methods
    static EmergencyCenter* getInstance();
    
    // Other methods
    void addComponent(std::shared_ptr<Component> component);
    void removeComponent(Component* component);
    void testComponent(Component* component, int mode);

    void printAllComponents();
    void activateComponent(Component* component, int mode);
    void activateAllComponents(int mode);
    void deactivateComponent(Component* component, int mode);
    void deactivateAllComponents(int mode);
    void testAllComponents(int mode);
    void updateAllSoftwares();

    // Orderby methods Component vector (components)
    void orderByComponentId();
    void orderByComponentLocation();
    void orderByComponentVendor();

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center);
};

#endif // EMERGENCYCENTER_H
