#pragma once
#ifndef SENSOR_H
#define SENSOR_H
#include "Component.h"

class Sensor: public Component {
    public:
        Sensor() = default;
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion);

        // virtual void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        // virtual void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        // virtual void executeStrategy() const override;

        // virtual std::string getLocation() const override;

        // virtual void setLocation(const std::string& location) override;

        // virtual std::string getVendor() const override;

        // virtual void setVendor(const std::string& vendor) override;

        // virtual void updateSoftware();

        // virtual int getSoftwareVersion() const;
    
    // protected:
    //     std::string location;
    //     std::string vendor;
    //     int softwareVersion;
    //     std::vector<std::shared_ptr<SensorStrategy>> strategies;
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

#endif 

