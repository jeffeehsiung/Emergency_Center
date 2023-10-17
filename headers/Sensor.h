#include "SensorStrategy.h"
#include "Component.h"

class Sensor: public Component {
public:
    virtual std::string getVendor() const {
        return vendor;
    }

    virtual std::string getLocation() const {
        return location;
    }

    virtual std::string getFabrication() const {
        return fabrication;
    }

    virtual std::string getSoftwareVersion() const {
        return softwareVersion;
    }

    virtual void addStrategy(SensorStrategy* sensorStrategy){
        strategies.push_back(sensorStrategy);
    }

    virtual void removeStrategy(SensorStrategy* sensorStrategy){
        strategies.erase(std::remove(strategies.begin(), strategies.ends(), sensorStrategy), strategies.end());
    }


protected:
    std::string vendor;
    std::string location;
    std::string fabrication;
    std::string softwareVersion;
    std::vector<SensorStrategy*> strategies;
};
