#include "SensorStrategy.h"
#include "Component.h"

class Sensor: public Component {
public:
    virtual string getVendor() const {
        return vendor;
    }

    virtual string getLocation() const {
        return location;
    }

    virtual string getFabrication() const {
        return fabrication;
    }

    virtual string getSoftwareVersion() const {
        return softwareVersion;
    }

    virtual void addStrategy(SensorStrategy* sensorStrategy){
        strategies.push_back(sensorStrategy);
    }

    virtual void removeStrategy(SensorStrategy* sensorStrategy){
        strategies.erase(std::remove(strategies.begin(), strategies.ends(), sensorStrategy), strategies.end());
    }


protected:
    string vendor;
    string location;
    string fabrication;
    string softwareVersion;
    vector<SensorStrategy*> strategies;
};
