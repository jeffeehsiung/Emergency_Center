#include "headers/EmergencyCenter.h"

// Initialize the singleton instance as null
EmergencyCenter* EmergencyCenter::instance = nullptr;

EmergencyCenter::EmergencyCenter() {
    // Initialization (if needed)
}

EmergencyCenter::~EmergencyCenter() {
    // Use overloaded -- operator to destruct components
    while (!components.empty()) {
        --(*this);
    }
}

// Singleton instance getter
EmergencyCenter* EmergencyCenter::getInstance() {
    if (!instance) {
        instance = new EmergencyCenter();
    }
    return instance;
}

// Overloaded << operator for Component's monitor scope
std::ostream& operator<<(std::ostream& out, const std::list<std::string>& list) {
    out << "[";
    for (const auto& item : list) {
        out << item;
        if (&item != &list.back()) out << ", ";
    }
    out << "]";
    return out;
}

// Overloaded << operator for Component's monitor scope
std::ostream& operator<<(std::ostream& out, const Component& component) {
    // Print component details using its getter methods
    out << "ID: " << component.getId() << "\n"
        << "Location: " << component.getLocation() << "\n"
        << "Vendor: " << component.getVendor() << "\n"
        << "Activation time: " << component.getActivationTimeStart() << " to " << component.getActivationTimeEnd() << "\n"
        << "Monitor scope: " << component.getMonitorScope() << "\n"
        << "Is active? " << component.getIsActive() << "\n"
        << "Is always active? " << component.getAlwaysActive() << "\n"
        << "Deactivation time: " << component.getDeactivationTime() << "\n";
    return out;
}

// Overloaded << operator for EmergencyCenter
std::ostream& operator<<(std::ostream& out, const EmergencyCenter& center) {
    for (const auto& comp : center.components) {
        out << *comp << "\n";
    }
    return out;
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

// Overloaded ++ operator for EmergencyCenter
EmergencyCenter& EmergencyCenter::operator++() {
    Component* newComp = nullptr;  // Logic to add a component if necessary
    components.push_back(newComp);
    return *this;
}

// Overloaded -- operator for EmergencyCenter
EmergencyCenter& EmergencyCenter::operator--() {
    if (!components.empty()) {
        delete components.back();
        components.pop_back();
    }
    return *this;
}

void EmergencyCenter::addComponent(Component* component) {
    ++(*this);
}

void EmergencyCenter::removeComponent(Component* component) {
    auto it = std::remove(components.begin(), components.end(), component);
    if (it != components.end()) {
        --(*this);
    }
}

void EmergencyCenter::printAllComponents() {
    std::cout << *this;
}

void EmergencyCenter::activateComponent(Component* component) {
    // Need logic to activate the component
    ++(*component);
}

void EmergencyCenter::deactivateComponent(Component* component) {
    // Need logic to deactivate the component
    --(*component);
}

bool EmergencyCenter::testComponent(Component* component) {
    // Need logic to test the component
    return component->getIsActive();
}

void EmergencyCenter::activateAllComponents() {
    for (auto& comp : components) {
        activateComponent(comp);
    }
}

void EmergencyCenter::deactivateAllComponents() {
    for (auto& comp : components) {
        deactivateComponent(comp);
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
