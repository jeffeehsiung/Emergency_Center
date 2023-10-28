#include "headers/Sensor.h"

// constructor
Sensor::Sensor(std::string id, std::string location, std::string vendor, int activationTimeStart, int activationTimeEnd, bool isActive, bool alwaysActive, int deactivationTime, int softwareVersion):
    Component(id, activationTimeStart, activationTimeEnd, isActive, alwaysActive, deactivationTime)
{
    this->location = location;
    this->vendor = vendor;
    this->softwareVersion = softwareVersion;
}

std::string Sensor::getLocation() const{
    return location;
}

void Sensor::setLocation(const std::string& location){
    this->location = location;
}

std::string Sensor::getVendor() const{
    return vendor;
}

void Sensor::setVendor(const std::string& vendor){
    this->vendor = vendor;
}

void Sensor::updateSoftware(){
    this->softwareVersion++;
}

int Sensor::getSoftwareVersion() const
{
    return softwareVersion;
}

void Sensor::setActive()
{
    this->isActive = true;
}

void Sensor::setNotActive()
{
    this->isActive = false;
}

int Sensor::getSoftwareVersion() const{
    return softwareVersion;
}

Component &Sensor::operator++()
{
    // set active
    this->setActive();
    return *this;
}

Component &Sensor::operator--()
{
    // set not active
    this->setNotActive();
    return *this;
}
