#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "headers/Component.h"

class EmergencyCenter {
private:
    static EmergencyCenter* instance; // Singleton instance
    std::list<std::unique_ptr<Component>> components;

public:
    // Constructor & Destructor
    EmergencyCenter();
    ~EmergencyCenter();

    // Singleton related methods
    static EmergencyCenter* getInstance();
    
    // Other methods
    void EmergencyCenter::addComponent(std::unique_ptr<Component> component);
    void EmergencyCenter::removeComponent(Component* component);
    bool EmergencyCenter::testComponent(Component* component);

    void printAllComponents();
    void activateAllComponents();
    void deactivateAllComponents();
    bool testAllComponents();
    void updateAllSoftwares();

    // Operator overloading methods
    friend std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center);
};

#endif // EMERGENCYCENTER_H
