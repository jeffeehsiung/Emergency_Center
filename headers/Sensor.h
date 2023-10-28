#pragma once
#ifndef SENSOR_H
#define SENSOR_H
#include "Component.h"

class Sensor: public Component {
    public:
        // constructor
        Sensor(std::string id): Component(id){}
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion);

        /** sensor specific methods */
        virtual std::string getLocation() const;

        virtual void setLocation(const std::string& location);

        virtual std::string getVendor() const;

        virtual void setVendor(const std::string& vendor);

        virtual void updateSoftware();

        virtual int getSoftwareVersion() const;

        virtual void setActive();

        virtual void setNotActive();

        /** Operator overloading methods */
        virtual Component& operator++();

        virtual Component& operator--();

    
    protected:
        bool isActive;
        std::string location;
        std::string vendor;
        int softwareVersion;
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

