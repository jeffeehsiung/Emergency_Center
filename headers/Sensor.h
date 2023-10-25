#include "Component.h"
#include "SensorStrategy.h"

class Sensor: public Component {
    public:
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, time_t fabricationDate);

        time_t getFabricationDate() const{return fabricationDate;};

        void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        void executeStrategy() const override;

        std::string getLocation() const;

        void setLocation(const std::string& location);

        std::string getVendor() const;

        void setVendor(const std::string& vendor);

        void updateSoftware();

        int getSoftwareVersion() const;
    
    protected:
        time_t fabricationDate;
        std::string location;
        std::string vendor;
        int softwareVersion;
        std::vector<std::shared_ptr<SensorStrategy>> strategies;
};
