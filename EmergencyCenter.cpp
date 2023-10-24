#include "headers/EmergencyCenter.h"

// Initialize the singleton instance as null
EmergencyCenter* EmergencyCenter::instance = nullptr;

EmergencyCenter::EmergencyCenter() {
    // Initialization (if needed)
}

EmergencyCenter::~EmergencyCenter() {
    for (Component* component : components) {
        delete component;
    }
    components.clear();
}

// Singleton instance getter
EmergencyCenter* EmergencyCenter::getInstance() {
    if (!instance) {
        instance = new EmergencyCenter();
    }
    return instance;
}

// Overloaded << operator for Component's monitor scope
std::ostream& operator<<(std::ostream& COUT, const std::list<std::string>& list) {
    COUT << "[";
    for (const auto& item : list) {
        COUT << item;
        if (&item != &list.back()) COUT << ", ";
    }
    COUT << "]";
    return COUT;
}

// Overloaded << operator for Component
std::ostream& operator<<(std::ostream& COUT, const Component& component) {
    // Print component details using its getter methods
    COUT << "ID: " << component.getId() << "\n"
        << "Location: " << component.getLocation() << "\n"
        << "Vendor: " << component.getVendor() << "\n"
        << "Activation time: " << component.getActivationTimeStart() << " to " << component.getActivationTimeEnd() << "\n"
        << "Monitor scope: " << component.getMonitorScope() << "\n"
        << "Is active? " << component.getIsActive() << "\n"
        << "Is always active? " << component.getAlwaysActive() << "\n"
        << "Deactivation time: " << component.getDeactivationTime() << "\n\n\n";
    return COUT;
}

// Overloaded << operator for EmergencyCenter
std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center) {
    for (const auto& comp : center.components) {
        COUT << *comp << "\n";
    }
    return COUT;
}

// Overloaded ++ operator for Component
Component& Component::operator++() {
    this->setActive();
    return *this;
}

// Overloaded -- operator for Component
Component& Component::operator--() {
    this->setNotActive();
    return *this;
}

void EmergencyCenter::addComponent(Component* component) {
    components.push_back(component);
}

void EmergencyCenter::removeComponent(Component* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end()) {
        delete *it;                // Release the memory for the component
        components.erase(it);      // Remove the pointer from the list
    }
}

void EmergencyCenter::printAllComponents() {
    std::cout << *this;
}

bool EmergencyCenter::testComponent(Component* component) {
    // Need logic to test the component
    return component->getIsActive();
}

void EmergencyCenter::activateAllComponents() {
    for (auto& comp : components) {
        ++(*comp);
    }
}

void EmergencyCenter::deactivateAllComponents() {
    for (auto& comp : components) {
        --(*comp);
    }
}

bool EmergencyCenter::testAllComponents() {
    return std::all_of(components.begin(), components.end(), [](Component* comp) { return comp->getIsActive(); });
}

void EmergencyCenter::updateAllSoftwares() {
    for (auto& comp : components) {
        comp->updateSoftware();
    }
}
