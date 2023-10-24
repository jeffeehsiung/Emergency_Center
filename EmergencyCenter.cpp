#include "headers/EmergencyCenter.h"

// Initialize the singleton instance as null
EmergencyCenter* EmergencyCenter::instance = nullptr;

EmergencyCenter::EmergencyCenter() {
    // Initialization (if needed)
}

EmergencyCenter::~EmergencyCenter() = default;

// Singleton instance getter
EmergencyCenter* EmergencyCenter::getInstance() {
    if (!instance) {
        instance = new EmergencyCenter();
    }
    return instance;
}

// Overloaded << operator for EmergencyCenter
std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center) {
    for (const auto& comp : center.components) {
        COUT << *comp << "\n";
    }
    return COUT;
}

void EmergencyCenter::addComponent(std::unique_ptr<Component> component) {
    components.push_back(std::move(component));
}

void EmergencyCenter::removeComponent(Component* component) {
    auto it = std::find_if(components.begin(), components.end(),
                           [component](const std::unique_ptr<Component>& compPtr) { return compPtr.get() == component; });
    if (it != components.end()) {
        components.erase(it);
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
