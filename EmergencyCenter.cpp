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
    COUT << "***************************************" << std::endl;
    COUT << "Emergency Center has the following components:" << std::endl;
    for (const auto& comp : center.components) {
        printComponentDetails(COUT, comp);
    }
    COUT << "***************************************" << std::endl;
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

void EmergencyCenter::testComponent(Component* component, int mode) {
    // If it's a sensor, directly print its active status
    if (auto sensor = dynamic_cast<Sensor*>(component)) {
        if (mode == 1 && dynamic_cast<Gas*>(component)) {
            if(sensor->getIsActive()){
                sensor->executeStrategy();
            }
            std::cout << "Sensor " << sensor->getId() << " is " << (sensor->getIsActive() ? "active" : "not active") << "\n";
        }
        else if (mode == 2 && dynamic_cast<Motion*>(component)) {
            if(sensor->getIsActive()){
                sensor->executeStrategy();
            }
            std::cout << "Sensor " << sensor->getId() << " is " << (sensor->getIsActive() ? "active" : "not active") << "\n";
        }
        else if (mode == 3 && dynamic_cast<Smoke*>(component)) {
            if(sensor->getIsActive()){
                sensor->executeStrategy();
            }
            std::cout << "Sensor " << sensor->getId() << " is " << (sensor->getIsActive() ? "active" : "not active") << "\n";
        }
        else if(mode == 0){
            if(sensor->getIsActive()){
                sensor->executeStrategy();
            }
            // If you want to activate all sensors, regardless of their type
            std::cout << "Sensor " << sensor->getId() << " is " << (sensor->getIsActive() ? "active" : "not active") << "\n";
        }
    }
    
    // If it's a sensor group, check each component in the group
    else if (auto group = dynamic_cast<SensorGroup*>(component)) {
        for (const auto& nestedComp : group->getComponents()) {
            testComponent(nestedComp.get(), mode); // Recursively test and print
        }
    }
}

void EmergencyCenter::activateComponent(Component* component, int mode) {
    Sensor* asSensor = dynamic_cast<Sensor*>(component); // Try to cast component to Sensor
    if (auto group = dynamic_cast<SensorGroup*>(component)) {
        for (const auto& nestedComp : group->getComponents()) {
            activateComponent(nestedComp.get(), mode);
        }
    }
    
    if (!asSensor) return; // If the cast failed (not a Sensor), return early

    if (mode == 1 && dynamic_cast<Gas*>(component)) {
        ++(*asSensor);
    }
    else if (mode == 2 && dynamic_cast<Motion*>(component)) {
        ++(*asSensor);
    }
    else if (mode == 3 && dynamic_cast<Smoke*>(component)) {
        ++(*asSensor);
    }
    else if(mode == 0){
        // If you want to activate all sensors, regardless of their type
        ++(*asSensor);
    }

    // Handle SensorGroup
    
}

void EmergencyCenter::activateAllComponents(int mode) {
    for (auto& comp : components) {
        activateComponent(comp.get(), mode);
    }
}

void EmergencyCenter::deactivateComponent(Component* component, int mode) {
    Sensor* asSensor = dynamic_cast<Sensor*>(component); // Try to cast component to Sensor
    if (auto group = dynamic_cast<SensorGroup*>(component)) {
        for (const auto& nestedComp : group->getComponents()) {
            deactivateComponent(nestedComp.get(), mode);
        }
    }
    
    if (!asSensor) return; // If the cast failed (not a Sensor), return early

    if (mode == 1 && dynamic_cast<Gas*>(component)) {
        --(*asSensor);
    }
    else if (mode == 2 && dynamic_cast<Motion*>(component)) {
        --(*asSensor);
    }
    else if (mode == 3 && dynamic_cast<Smoke*>(component)) {
        --(*asSensor);
    }
    else if(mode == 0){
        // If you want to activate all sensors, regardless of their type
        --(*asSensor);
    }

    // Handle SensorGroup
    
}

void EmergencyCenter::deactivateAllComponents(int mode) {
    for (auto& comp : components) {
        deactivateComponent(comp.get(), mode);
    }
}


void EmergencyCenter::testAllComponents(int mode) {
    for (auto& comp : components) {
        testComponent(comp.get(), mode);
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
    // Define a new vector list to store the sorted components
    std::vector<std::shared_ptr<Component>> sortedComponents;
    // iterate through the components vector and extract each sensor component from sensor and sensor group
    for (const auto& comp : components) {
        Sensor* sensor = dynamic_cast<Sensor*>(comp.get());
        if (sensor) {
            // It's a Sensor, so call the sensor-specific function
            sortedComponents.push_back(comp);
        }
        else if (auto group = dynamic_cast<SensorGroup*>(comp.get())) {
            for (const auto& nestedComp : group->getComponents()) {
                // recursively check if the nested component is a sensor or sensor group
                Sensor* sensor = dynamic_cast<Sensor*>(nestedComp.get());
                if (sensor) {
                    // It's a Sensor, so call the sensor-specific function
                    sortedComponents.push_back(nestedComp);
                }else if(auto nestedGroup = dynamic_cast<SensorGroup*>(nestedComp.get())){
                    for (const auto& nestedNestedComp : nestedGroup->getComponents()) {
                        Sensor* sensor = dynamic_cast<Sensor*>(nestedNestedComp.get());
                        if (sensor) {
                            // It's a Sensor, so call the sensor-specific function
                            sortedComponents.push_back(nestedNestedComp);
                        }
                    }
                }
            }
        }
    }
    
    // Sort the new vector list composed of only Sensor class objects, sortedComponents, by id
    std::sort(sortedComponents.begin(), sortedComponents.end(), [](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
        const Sensor* sensorA = dynamic_cast<Sensor*>(a.get());
        const Sensor* sensorB = dynamic_cast<Sensor*>(b.get());
        return sensorA->getId() < sensorB->getId();
    });

    // replace the components vector with the sortedComponents vector
    components = sortedComponents;
}

void EmergencyCenter::orderByComponentLocation(){
    // Define a new vector list to store the sorted components
    std::vector<std::shared_ptr<Component>> sortedComponents;
    // iterate through the components vector and extract each sensor component from the components vector
    for (const auto& comp : components) {
        Sensor* sensor = dynamic_cast<Sensor*>(comp.get());
        if (sensor) {
            // It's a Sensor, so call the sensor-specific function
            sortedComponents.push_back(comp);
            this->removeComponent(comp.get());
        }
    }
    // now only sensor group objects are left in the components vector
    // iterate through the components vector and extract each sensor component from sensor group
    while(auto sensorGroup = std::dynamic_pointer_cast<SensorGroup>(components.front())){
        for (const auto& nestedComp : sensorGroup->getComponents()) {
            // if the nested component is a sensor, add it to the sortedComponents vector
            Sensor* sensor = dynamic_cast<Sensor*>(nestedComp.get());
            if (sensor) {
                // It's a Sensor, so call the sensor-specific function
                sortedComponents.push_back(nestedComp);
                this->removeComponent(nestedComp.get());
            // else the the component is a sensorgroup, so iterate through the sensorgroup and extract each sensor component from sensor group
            }else if(auto nestedGroup = dynamic_cast<SensorGroup*>(nestedComp.get())){
                for (const auto& nestedNestedComp : nestedGroup->getComponents()) {
                    Sensor* sensor = dynamic_cast<Sensor*>(nestedNestedComp.get());
                    if (sensor) {
                        // It's a Sensor, so call the sensor-specific function
                        sortedComponents.push_back(nestedNestedComp);
                        this->removeComponent(nestedNestedComp.get());
                    }
                }
            }
        }
        // remove this sensor group component from the components vector
        this->removeComponent(sensorGroup.get());
    }

    // Sort the new vector list composed of only Sensor class objects, sortedComponents, by location
    std::sort(sortedComponents.begin(), sortedComponents.end(), [](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
        const Sensor* sensorA = dynamic_cast<Sensor*>(a.get());
        const Sensor* sensorB = dynamic_cast<Sensor*>(b.get());
        return sensorA->getLocation() < sensorB->getLocation();
    });

    // replace the components vector with the sortedComponents vector
    components = sortedComponents;
}

void EmergencyCenter::orderByComponentVendor(){
    // Define a new vector list to store the sorted components
    std::vector<std::shared_ptr<Component>> sortedComponents;
    // iterate through the components vector and extract each sensor component from sensor and sensor group
    for (const auto& comp : components) {
        Sensor* sensor = dynamic_cast<Sensor*>(comp.get());
        if (sensor) {
            // It's a Sensor, so call the sensor-specific function
            sortedComponents.push_back(comp);
        }
        else if (auto group = dynamic_cast<SensorGroup*>(comp.get())) {
            for (const auto& nestedComp : group->getComponents()) {
                Sensor* sensor = dynamic_cast<Sensor*>(nestedComp.get());
                if (sensor) {
                    // It's a Sensor, so call the sensor-specific function
                    sortedComponents.push_back(nestedComp);
                }else if(auto nestedGroup = dynamic_cast<SensorGroup*>(nestedComp.get())){
                    for (const auto& nestedNestedComp : nestedGroup->getComponents()) {
                        Sensor* sensor = dynamic_cast<Sensor*>(nestedNestedComp.get());
                        if (sensor) {
                            // It's a Sensor, so call the sensor-specific function
                            sortedComponents.push_back(nestedNestedComp);
                        }
                    }
                }
            }
        }
    }
    // Sort the new vector list composed of only Sensor class objects, sortedComponents, by vendor
    std::sort(sortedComponents.begin(), sortedComponents.end(), [](const std::shared_ptr<Component>& a, const std::shared_ptr<Component>& b) -> bool {
        const Sensor* sensorA = dynamic_cast<Sensor*>(a.get());
        const Sensor* sensorB = dynamic_cast<Sensor*>(b.get());
        return sensorA->getVendor() < sensorB->getVendor();
    });

    // replace the components vector with the sortedComponents vector
    components = sortedComponents;
}