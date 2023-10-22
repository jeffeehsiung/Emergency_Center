#pragma once

// SensorStrategy strategy interface is the base class for all concrete strategy classes including concrete strategy classes of EmergencyStrategy, ActionStrategy, NotificationStrategy, and AlarmStrategy. 
// The SensorStrategy interface class is defined in the header file SensorStrategy.h. The SensorStrategy interface class is shown below:
#ifndef SENSORSTRATEGY_H
#define SENSORSTRATEGY_H

// Interface is an abstract class with only pure virtual functions.
// the functions are virtual and set to 0, which means they have no implementation.
// the functions should be implemented in the derived classes.
#include <iostream>

class SensorStrategy
{
public:
    virtual ~SensorStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() = 0;
};

#endif  // SENSORSTRATEGY_H

