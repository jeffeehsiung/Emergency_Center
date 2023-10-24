#include "headers/SensorStrategy.h"
#include "headers/Component.h"

class Sensor: public Component {
    private:
        std::string vendor;
        std::string location;
        time_t fabricationDate;
        int softwareVersion;
        std::vector<SensorStrategy*> strategies;
    public:
        Sensor(std::string vn, std::string lo, time_t fd, int sv);

        const std::string getVendor() const {return vendor};

        std::string getLocation() const{return location};

        time_t getFabricationDate() const{return fabricationDate};

        int getSoftwareVersion() const{return softwareVersion};

        virtual void addStrategy(SensorStrategy* sensorStrategy);

        virtual void removeStrategy(SensorStrategy* sensorStrategy);
};
