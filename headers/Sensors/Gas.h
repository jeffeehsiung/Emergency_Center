#pragma once
#ifndef GAS_H
#define GAS_H
#include "../Sensor.h"

class Gas : public Sensor
{
    using Sensor::Sensor;
    private:
        std::string gasType;
        int amount;
    public:
        Gas(std::string id, std::string location, std::string vendor, int activationTimeStart, 
        int activationTimeEnd, bool isActive, bool alwaysActive, int softwareVersion, std::string type, int capacity);
        ~Gas(){};
        virtual void setGasType(const std::string& type);
        virtual std::string getGasType() const {return gasType;};
        virtual void setAmount(const int type);
        virtual int getAmount() const {return amount;};
        void printDetails(std::ostream& COUT) const override {
            Sensor::printDetails(COUT);
            COUT << "Sensor Type: " << "Gas" << "\n";
            COUT << "Gas Type: " << getGasType() << "\n";
            COUT << "Capacity: " << getAmount() << "\n";
        }
};

#endif 