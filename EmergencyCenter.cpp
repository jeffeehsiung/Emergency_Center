#include "headers/EmergencyCenter.h"

// Initialize static member
EmergencyCenter* EmergencyCenter::instance = nullptr;

// Constructor
EmergencyCenter::EmergencyCenter() {}

// Destructor
EmergencyCenter::~EmergencyCenter() {
    for (Component* component : components) {
        delete component;
    }
    components.clear();
}

// Singleton getInstance method
EmergencyCenter* EmergencyCenter::getInstance() {
    if (!instance) {
        instance = new EmergencyCenter();
    }
    return instance;
}

void EmergencyCenter::addComponent(Component* component) {
    components.push_back(component);
}

void EmergencyCenter::printAllSensorsOrderedById() {
    std::sort(components.begin(), components.end(), [](Component* a, Component* b) {
        return a->getId() < b->getId();
    });
    for (Component* component : components) {
        std::cout << component->getId() << std::endl;
    }
}

void EmergencyCenter::printAllSensorsOrderedByLocation() {
    std::sort(components.begin(), components.end(), [](Component* a, Component* b) {
        return a->getLocation() < b->getLocation();
    });
    for (Component* component : components) {
        std::cout << component->getLocation() << std::endl;
    }
}

void EmergencyCenter::printAllSensorsOrderedByVendor() {
    std::sort(components.begin(), components.end(), [](Component* a, Component* b) {
        return a->getVendor() < b->getVendor();
    });
    for (Component* component : components) {
        std::cout << component->getVendor() << std::endl;
    }
}

void EmergencyCenter::activateAllSensors() {
    for (Component* component : components) {
        component->setActive();
    }
}

void EmergencyCenter::deactivateAllSensors() {
    for (Component* component : components) {
        component->setNotActive();
    }
}

bool EmergencyCenter::testAllSensors() {
    for (Component* component : components) {
        if (!component->getIsActive()) {
            return false;
        }
    }
    return true;
}

void EmergencyCenter::activateComponent(Component* component) {
    component->setActive();
}

void EmergencyCenter::deactivateComponent(Component* component) {
    component->setNotActive();
}

bool EmergencyCenter::testComponent(Component* component) {
    if (!component->getIsActive()) {
        return false;
    }
    return true;
}

void EmergencyCenter::updateAllSoftware() {
    for (Component* component : components) {
        component->updateSoftware();
    }
}
