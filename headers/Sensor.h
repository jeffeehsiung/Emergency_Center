#include "SensorStrategy.h"
#include "Component.h"

class Sensor: public Component {
    protected:
        std::string vendor;
        std::string location;
        std::string fabrication;
        int softwareVersion;
        std::vector<SensorStrategy*> strategies;
    public:
        virtual std::string getVendor();

        virtual std::string getLocation();

        virtual std::string getFabrication();

        virtual int getSoftwareVersion();

        virtual void addStrategy(SensorStrategy* sensorStrategy);

        virtual void removeStrategy(SensorStrategy* sensorStrategy);
};
