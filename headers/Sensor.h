#include "Component.h"
#include "SensorStrategy.h"

class Sensor: public Component {
    public:
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
        virtual void setGasType(const std::string& type);
        virtual std::string getGasType();
};

class Motion : public Sensor
{
    using Sensor::Sensor;
    private:
        int activationRange;
    public:
        virtual void setActivationRange(const int type);
        virtual int getActivationRange();
};

class Smoke : public Sensor
{
    using Sensor::Sensor;
    private:
        int threshold;
    public:
        virtual void setThreshold(const int type);
        virtual int getThreshold();
};


