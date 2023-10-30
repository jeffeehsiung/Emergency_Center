#pragma once
// NotificationStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef NOTIFICATIONSTRATEGY_H
#define NOTIFICATIONSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>
#include <string>

class NotificationStrategy : public SensorStrategy
{
public:
    virtual ~NotificationStrategy() = default; // the derived class can rely on the base class destructor.
    // override the executeStrategy() function from the base class.
    virtual void executeStrategy() const override = 0;
    // virtual void executeStrategy() const = 0;
};

#endif  // NOTIFICATIONSTRATEGY_H