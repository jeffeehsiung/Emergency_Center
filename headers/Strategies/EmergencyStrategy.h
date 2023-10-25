#pragma once
// EmergencyStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef EMERGENCYSTRATEGY_H
#define EMERGENCYSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class EmergencyStrategy : public SensorStrategy
{
public:
    virtual ~EmergencyStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() const override = 0;
};

class CentralDispatch : public EmergencyStrategy
{
public:
    CentralDispatch(){};
    ~CentralDispatch(){};
    virtual void executeStrategy() const override;
};

class FireBrigade : public EmergencyStrategy
{
public:
    FireBrigade(){};
    ~FireBrigade(){};
    virtual void executeStrategy() const override;
};

class Police : public EmergencyStrategy
{
public:
    Police(){};
    ~Police(){};
    virtual void executeStrategy() const override;
};


class Security : public EmergencyStrategy
{
public:
    Security(){};
    ~Security(){};
    virtual void executeStrategy() const override;
};


#endif  // EMERGENCYSTRATEGY_H



