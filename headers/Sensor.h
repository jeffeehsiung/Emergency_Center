#pragma once
#ifndef SENSOR_H
#define SENSOR_H
#include "Component.h"

class Sensor: public Component {
    public:
        // constructor
        Sensor(std::string id): Component(id){}
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion);

        void printDetails(std::ostream& COUT) const override {
            Component::printDetails(COUT);
            COUT << "Is active? " << (getIsActive() ? "Yes" : "No") << "\n"  // Ternary to print Yes/No instead of 1/0
            << "Location: " << getLocation() << "\n"
            << "Vendor: " << getVendor() << "\n"
            << "Software Version: " << getSoftwareVersion() << "\n";
        }
         /** sensor specific methods */
        virtual std::string getLocation() const;

        virtual void setLocation(const std::string& location);

        virtual std::string getVendor() const;

        virtual void setVendor(const std::string& vendor);

        virtual void updateSoftware();

        virtual int getSoftwareVersion() const;

        virtual void setActive();

        virtual void setNotActive();

        virtual bool getIsActive() const {return isActive;};

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
        int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, std::string type);
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
        int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, int activationRange);
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
        int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, int threshold);
        virtual void setThreshold(const int type);
        virtual int getThreshold() const {return threshold;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Smoke" << "\n";
            COUT << "Threshold: " << getThreshold() << "\n";
        }
        
};

#endif 

