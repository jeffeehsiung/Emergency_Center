#include "headers/EmergencyCenter.h"
#include "EmergencyCenter.h"

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
    return dynamic_cast<Sensor*>(component)->getIsActive();
}

void EmergencyCenter::activateAllComponents(int mode) {
    if(mode == 1){
        for (auto& comp : components) {
        Gas* sensor = dynamic_cast<Gas*>(comp.get());
        if (sensor) {
            ++(*sensor);
        }
        } 
    }
    else if(mode == 2){
        for (auto& comp : components) {
        Motion* sensor = dynamic_cast<Motion*>(comp.get());
        if (sensor) {
            ++(*sensor);
        }
        } 
    }
    else if(mode == 3){
        for (auto& comp : components) {
        Smoke* sensor = dynamic_cast<Smoke*>(comp.get());
        if (sensor) {
            ++(*sensor);
        }
        } 
    }
    // else{
    //     for (auto& comp : components) {
    //         ++(*comp);
    // }
    // }
}

void EmergencyCenter::deactivateAllComponents(int mode) {
    if(mode == 1){
        for (auto& comp : components) {
        Gas* sensor = dynamic_cast<Gas*>(comp.get());
        if (sensor) {
            --(*sensor);
        }
        } 
    }
    else if(mode == 2){
        for (auto& comp : components) {
        Motion* sensor = dynamic_cast<Motion*>(comp.get());
        if (sensor) {
            --(*sensor);
        }
        } 
    }
    else if(mode == 3){
        for (auto& comp : components) {
        Smoke* sensor = dynamic_cast<Smoke*>(comp.get());
        if (sensor) {
            --(*sensor);
        }
        } 
    }
    // else{
    //     for (auto& comp : components) {
    //         --(*comp);
    // }
    // }
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
        return true;
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
void EmergencyCenter::orderByComponentId()
{
    // Define a lambda comparator function
    auto idComparator = [this](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
        // Helper function for recursive ID comparison
        std::function<bool(const std::shared_ptr<Component>&, const std::shared_ptr<Component>&)> compareId;

        compareId = [&compareId](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
            const Sensor* sensorA = dynamic_cast<Sensor*>(a.get());
            const Sensor* sensorB = dynamic_cast<Sensor*>(b.get());

            if (sensorA && sensorB) {
                // Both components are Sensor objects
                return sensorA->getId() < sensorB->getId();
            } else if (dynamic_cast<SensorGroup*>(a.get())) {
                // Component 'a' is a SensorGroup
                const auto& sensorsInGroup = std::dynamic_pointer_cast<SensorGroup>(a)->getComponents();
                for (const auto& sensor : sensorsInGroup) {
                    // Recursively compare the ID of each sensor in the group with component 'b'
                    if (compareId(sensor, b)) {
                        return true;  // If any sensor in the group has a greater ID, return true.
                    }
                }
            } else if (dynamic_cast<SensorGroup*>(b.get())) {
                // Component 'b' is a SensorGroup
                const auto& sensorsInGroup = std::dynamic_pointer_cast<SensorGroup>(b)->getComponents();
                for (const auto& sensor : sensorsInGroup) {
                    // Recursively compare the ID of each sensor in the group with component 'a'
                    if (compareId(a, sensor)) {
                        return false;  // If any sensor in the group has a greater ID, return false.
                    }
                }
            }

            return false;  // If types are not comparable or no greater ID is found, return false.
        };

        return compareId(a, b);
    };

    // Use the lambda comparator in std::sort
    std::sort(components.begin(), components.end(), idComparator);
}

void EmergencyCenter::orderByComponentLocation(){
    // Define a lambda comparator function
    auto locationComparator = [this](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
        // Helper function for recursive location comparison
        std::function<bool(const std::shared_ptr<Component>&, const std::shared_ptr<Component>&)> compareLocation;

        compareLocation = [&compareLocation](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
            const Sensor* sensorA = dynamic_cast<Sensor*>(a.get());
            const Sensor* sensorB = dynamic_cast<Sensor*>(b.get());

            if (sensorA && sensorB) {
                // Both components are Sensor objects
                return sensorA->getLocation() < sensorB->getLocation();
            } else if (dynamic_cast<SensorGroup*>(a.get())) {
                // Component 'a' is a SensorGroup
                const auto& sensorsInGroup = std::dynamic_pointer_cast<SensorGroup>(a)->getComponents();
                for (const auto& sensor : sensorsInGroup) {
                    // Recursively compare the location of each sensor in the group with component 'b'
                    if (compareLocation(sensor, b)) {
                        return true;  // If any sensor in the group has a greater location, return true.
                    }
                }
            } else if (dynamic_cast<SensorGroup*>(b.get())) {
                // Component 'b' is a SensorGroup
                const auto& sensorsInGroup = std::dynamic_pointer_cast<SensorGroup>(b)->getComponents();
                for (const auto& sensor : sensorsInGroup) {
                    // Recursively compare the location of each sensor in the group with component 'a'
                    if (compareLocation(a, sensor)) {
                        return false;  // If any sensor in the group has a greater location, return false.
                    }
                }
            }

            return false;  // If types are not comparable or no greater location is found, return false.
        };

        return compareLocation(a, b);
    };

    // Use the lambda comparator in std::sort
    std::sort(components.begin(), components.end(), locationComparator);

}
