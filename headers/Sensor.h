#pragma once
#ifndef SENSOR_H
#define SENSOR_H
#include "Component.h"

class Sensor: public Component {
    public:
        // constructor
        Sensor(std::string id): Component(id){}
        Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion);
        virtual ~Sensor() = default;

        virtual void printDetails(std::ostream& COUT) const override {
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
        Component& operator++();

        Component& operator--();

    
    protected:
        bool isActive;
        std::string location;
        std::string vendor;
        int softwareVersion;
};

#endif 

