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
    void removeComponent(Component* component);
    void activateComponent(Component* component);
    void deactivateComponent(Component* component);
    bool testComponent(Component* component);

    void printAllComponents();
    void activateAllComponents();
    void deactivateAllComponents();
    bool testAllComponents();
    void updateAllSoftwares();

    // Overloading for printing all components
    friend std::ostream& operator<<(std::ostream& out, const EmergencyCenter& center);

    // Overloading for adding a component
    EmergencyCenter& operator++(); 

    // Overloading for removing a component
    EmergencyCenter& operator--();
};

#endif // EMERGENCYCENTER_H
