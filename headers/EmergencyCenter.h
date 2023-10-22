#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "Component.h"

class EmergencyCenter {
private:
    static EmergencyCenter* instance; // Singleton instance
    std::vector<Component*> components;

public:
    // Constructor & Destructor
    EmergencyCenter();
    ~EmergencyCenter();

    // Singleton related methods
    static EmergencyCenter* getInstance();
    
    // Other methods
    void addComponent(Component* component);
    void printAllSensorsOrderedById();
    void printAllSensorsOrderedByVendor();
    void printAllSensorsOrderedByLocation();
    void activateAllSensors();
    void deactivateAllSensors();
    bool testAllSensors();
    void activateComponent(Component* component);
    void deactivateComponent(Component* component);
    bool testComponent(Component* component);
    void updateAllSoftware();
};

#endif // EMERGENCYCENTER_H
