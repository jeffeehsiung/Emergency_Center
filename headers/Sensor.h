#pragma once
#ifndef SENSOR_H
#define SENSOR_H
#include "Component.h"

class Sensor: public Component {
    public:
        // constructor
        Sensor(std::string id): Component(id){}
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion);

        void printDetails(std::ostream& COUT) const override {
            Component::printDetails(COUT);
        }
        // virtual void addStrategy(std::shared_ptr<SensorStrategy> sensorStrategy);

        // virtual void removeStrategy(std::shared_ptr<SensorStrategy> sensorStrategy); 

        // virtual void executeStrategy() const override;

        // virtual std::string getLocation() const override;

        virtual void setLocation(const std::string& location);

        virtual std::string getVendor() const;

        virtual void setVendor(const std::string& vendor);

        virtual void updateSoftware();

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
        virtual std::string getGasType() const {return gasType;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Gas" << "\n";
            COUT << "Gas Type: " << getGasType() << "\n";
        }
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
        virtual int getActivationRange() const {return activationRange;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Motion" << "\n";
            COUT << "Activation Range: " << getActivationRange() << "\n";
        }
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
        virtual int getThreshold() const {return threshold;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Smoke" << "\n";
            COUT << "Threshold: " << getThreshold() << "\n";
        }
        
};

#endif 

