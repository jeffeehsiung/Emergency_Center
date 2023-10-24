#include "headers/Component.h"

class Sensor: public Component {
    public:
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, time_t fabricationDate);

        time_t getFabricationDate() const{return fabricationDate;};

        void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        void executeStrategy() const override;
    
    protected:
        time_t fabricationDate;
        std::vector<std::shared_ptr<SensorStrategy>> strategies;
};
