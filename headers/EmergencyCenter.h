#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include <string>
#include <vector>

// Forward declaration of the Component class to use as a pointer.
class Component;

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
    
    // Member functions as per the UML diagram
    void addComponent(Component* component);
    void printSensorsOrderedByLocation();
    void activateAllSensors();
    void deactivateAllSensors();
    bool testAllSensors();
    void activateComponent();
    void deactivateComponent();
    void testComponent();
    void updateAllSoftware();
};

#endif // EMERGENCYCENTER_H
