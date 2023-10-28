#include "Component.h"
#include "SensorStrategy.h"

class Sensor: public Component {
    public:
        Sensor() = default;
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion);

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
        std::string location;
        std::string vendor;
        int softwareVersion;
        std::vector<std::shared_ptr<SensorStrategy>> strategies;
};

class Gas : public Sensor
{
    using Sensor::Sensor;
    private:
        std::string gasType;
    public:
        Gas(std::string id, std::string location, std::string vendor, int activationTimeStart, 
        int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, std::string type);
        virtual void setGasType(const std::string& type);
        virtual std::string getGasType();
};

class Motion : public Sensor
{
    using Sensor::Sensor;
    private:
        int activationRange;
    public:
        Motion(std::string id, std::string location, std::string vendor, int activationTimeStart, 
        int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int activationRange);
        virtual void setActivationRange(const int type);
        virtual int getActivationRange();
};

class Smoke : public Sensor
{
    using Sensor::Sensor;
    private:
        int threshold;
    public:
        Smoke(std::string id, std::string location, std::string vendor, int activationTimeStart, 
        int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion, int threshold);
        virtual void setThreshold(const int type);
        virtual int getThreshold();
};


