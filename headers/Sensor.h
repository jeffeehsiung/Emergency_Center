#include <vector>
#include <string>
#include SensorStrategy.h
#include Component.h

Class Sensor: public Component {
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


protected:
    string vendor;
    string location;
    string fabrication;
    string softwareVersion;
    vector<SensorStrategy*> strategies;
};
