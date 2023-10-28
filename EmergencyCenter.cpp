#include "headers/EmergencyCenter.h"

// Initialize the singleton instance as null
std::unique_ptr<EmergencyCenter> EmergencyCenter::instance = nullptr;

EmergencyCenter::EmergencyCenter() {
    // Initialization (if needed)
}

EmergencyCenter::~EmergencyCenter() = default;

// Singleton instance getter
EmergencyCenter* EmergencyCenter::getInstance() {
    if (!instance) {
        instance = std::make_unique<EmergencyCenter>();
    }
    return instance.get();
}
void printComponentDetails(std::ostream& COUT, const std::shared_ptr<Component>& comp) {
    if (auto sensor = dynamic_cast<Sensor*>(comp.get())) {
        COUT << *sensor << "\n";
    }
    else if (auto group = dynamic_cast<SensorGroup*>(comp.get())) {
        for (const auto& nestedComp : group->getComponents()) {
            printComponentDetails(COUT, nestedComp);
        }
    }
}

// Overloaded << operator for EmergencyCenter
std::ostream& operator<<(std::ostream& COUT, const EmergencyCenter& center) {
    for (const auto& comp : center.components) {
        printComponentDetails(COUT, comp);
    }
    return COUT;
}

void EmergencyCenter::addComponent(std::shared_ptr<Component> component) {
    components.push_back(component);
}

void EmergencyCenter::removeComponent(Component* component) {
    auto it = std::remove_if(components.begin(), components.end(),
                             [component](const std::shared_ptr<Component>& compPtr) { return compPtr.get() == component; });
    components.erase(it, components.end());
}

void EmergencyCenter::printAllComponents() {
    std::cout << *this;
}

bool EmergencyCenter::testComponent(Component* component) {
    // Need logic to test the component
    return component->getIsActive();
}

void EmergencyCenter::activateAllComponents(int mode) {
    if(mode == 1){
        for (auto& comp : components) {
        Gas* sensor = dynamic_cast<Gas*>(comp.get());
        if (sensor) {
            ++(*comp);
        }
        } 
    }
    else if(mode == 2){
        for (auto& comp : components) {
        Motion* sensor = dynamic_cast<Motion*>(comp.get());
        if (sensor) {
            ++(*comp);
        }
        } 
    }
    else if(mode == 3){
        for (auto& comp : components) {
        Smoke* sensor = dynamic_cast<Smoke*>(comp.get());
        if (sensor) {
            ++(*comp);
        }
        } 
    }
    else{
        for (auto& comp : components) {
            ++(*comp);
    }
    }
}

void EmergencyCenter::deactivateAllComponents(int mode) {
    if(mode == 1){
        for (auto& comp : components) {
        Gas* sensor = dynamic_cast<Gas*>(comp.get());
        if (sensor) {
            --(*comp);
        }
        } 
    }
    else if(mode == 2){
        for (auto& comp : components) {
        Motion* sensor = dynamic_cast<Motion*>(comp.get());
        if (sensor) {
            --(*comp);
        }
        } 
    }
    else if(mode == 3){
        for (auto& comp : components) {
        Smoke* sensor = dynamic_cast<Smoke*>(comp.get());
        if (sensor) {
            --(*comp);
        }
        } 
    }
    else{
        for (auto& comp : components) {
            --(*comp);
    }
    }
}

bool EmergencyCenter::testAllComponents(int mode) {
    if(mode == 1){
        return std::all_of(components.begin(), components.end(), [](const std::shared_ptr<Component>& comp) {
        return dynamic_cast<Gas*>(comp.get()) != nullptr;
        }); 
    }
    else if(mode == 2){
        return std::all_of(components.begin(), components.end(), [](const std::shared_ptr<Component>& comp) {
        return dynamic_cast<Motion*>(comp.get()) != nullptr;
        });
    }
    else if(mode == 3){
        return std::all_of(components.begin(), components.end(), [](const std::shared_ptr<Component>& comp) {
        return dynamic_cast<Smoke*>(comp.get()) != nullptr;
        });
    }
    else{
        return std::all_of(components.begin(), components.end(), [](const std::shared_ptr<Component>& comp) { return comp->getIsActive(); });
    }
}

void EmergencyCenter::updateAllSoftwares() {
    for (auto& comp : components) {
        Sensor* sensor = dynamic_cast<Sensor*>(comp.get());
        if (sensor) {
            // It's a Sensor, so call the sensor-specific function
            sensor->updateSoftware();
        }
    }
}
