#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include <string>
#include <vector>
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
    void activateComponent();
    void deactivateComponent();
    void testComponent();
    void updateAllSoftware();
};

#endif // EMERGENCYCENTER_H
