#include "headers/SensorStrategy.h"
#include "headers/Component.h"

class Sensor: public Component {
    private:
        std::string vendor;
        std::string location;
        time_t fabricationDate;
        int softwareVersion;
        std::vector<std::shared_ptr<SensorStrategy>> strategies;

    public:
        Sensor(std::string vn, std::string lo, time_t fd, int sv);

        const std::string getVendor() const {return vendor};

        std::string getLocation() const{return location};

        time_t getFabricationDate() const{return fabricationDate};

        int getSoftwareVersion() const{return softwareVersion};

        void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        // override the executeStrategy method from Component
        virtual void executeStrategy() const override;
};
