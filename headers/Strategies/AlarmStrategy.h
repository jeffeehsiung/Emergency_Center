#pragma once
// AlarmStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ALARMSTRATEGY_H
#define ALARMSTRATEGY_H

#include "SensorStrategy.h"

class AlarmStrategy : public SensorStrategy
{
public:
    AlarmStrategy();
    ~AlarmStrategy();
    virtual void executeStrategy() const = 0;
};

#endif  // ALARMSTRATEGY_H
