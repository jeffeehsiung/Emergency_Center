#pragma once
// EmergencyStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef EMERGENCYSTRATEGY_H
#define EMERGENCYSTRATEGY_H

#include "SensorStrategy.h"

class EmergencyStrategy : public SensorStrategy
{
public:
    EmergencyStrategy();
    ~EmergencyStrategy();
    virtual void executeStrategy() const = 0;
};

#endif  // EMERGENCYSTRATEGY_H



