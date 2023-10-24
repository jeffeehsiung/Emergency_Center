#include "headers/Sensor.h"
#include "headers/SensorStrategy.h"

virtual std::string getVendor() {
    return vendor;
};

virtual std::string getLocation() {
    return location;
};

virtual std::string getFabrication() {
    return fabrication;
};

virtual int getSoftwareVersion() {
    return softwareVersion;
};

virtual void addStrategy(SensorStrategy* sensorStrategy) {
    strategies.push_back(sensorStrategy);
};

virtual void removeStrategy(SensorStrategy* sensorStrategy) {
    // Find and remove the specified strategy
    for (auto it = strategies.begin(); it != strategies.end(); ++it) {
        if (*it == sensorStrategy) {
            strategies.erase(it);
            break;  // Assuming there are no duplicate strategies
        }
    }
};