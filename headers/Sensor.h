#include "headers/SensorStrategy.h"
#include "headers/Component.h"
#include <memory> // for std::shared_ptr

class Sensor: public Component {
    public:
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int fabricationDate);

        time_t getFabricationDate() const{return fabricationDate};

        void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        void executeStrategy() const override;
    
    private:
        time_t fabricationDate;
        std::vector<std::shared_ptr<SensorStrategy>> strategies;
};
