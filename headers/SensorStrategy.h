#pragma once

// SensorStrategy strategy interface is the base class for all concrete strategy classes including concrete strategy classes of EmergencyStrategy, ActionStrategy, NotificationStrategy, and AlarmStrategy. 
// The SensorStrategy interface class is defined in the header file SensorStrategy.h. The SensorStrategy interface class is shown below:
#ifndef SENSORSTRATEGY_H
#define SENSORSTRATEGY_H

class SensorStrategy
{
public:
    SensorStrategy(){};
    virtual ~SensorStrategy(){};
    virtual void executeStrategy() = 0;
};

#endif  // SENSORSTRATEGY_H

