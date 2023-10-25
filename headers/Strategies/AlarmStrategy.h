#pragma once
// AlarmStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ALARMSTRATEGY_H
#define ALARMSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class AlarmStrategy : public SensorStrategy
{
public:
    virtual ~AlarmStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() const override = 0;
};

#endif  // ALARMSTRATEGY_H
