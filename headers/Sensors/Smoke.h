#pragma once
#ifndef SMOKE_H
#define SMOKE_H
#include "../Sensor.h"

class Smoke : public Sensor
{
    using Sensor::Sensor;
    private:
        int threshold;
    public:
        Smoke(std::string id, std::string location, std::string vendor, int activationTimeStart, 
        int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, int threshold);
        virtual ~Smoke() = default;
        virtual void setThreshold(const int type);
        virtual int getThreshold() const {return threshold;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Smoke" << "\n";
            COUT << "Threshold: " << getThreshold() << "\n";
        }
        
};

#endif 