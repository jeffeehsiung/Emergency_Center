#pragma once
#ifndef MOTION_H
#define MOTION_H
#include "../Sensor.h"

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

#endif 