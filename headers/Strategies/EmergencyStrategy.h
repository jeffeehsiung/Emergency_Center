#pragma once
// EmergencyStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef EMERGENCYSTRATEGY_H
#define EMERGENCYSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class EmergencyStrategy : public SensorStrategy
{
public:
    virtual void executeStrategy() const override = 0;
};


#endif  // EMERGENCYSTRATEGY_H



