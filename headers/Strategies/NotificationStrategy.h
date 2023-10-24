#pragma once
// NotificationStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef NOTIFICATIONSTRATEGY_H
#define NOTIFICATIONSTRATEGY_H

#include "headers/SensorStrategy.h"
#include <iostream>

class NotificationStrategy : public SensorStrategy
{
public:
    virtual ~NotificationStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() const = 0;
};


#endif  // NOTIFICATIONSTRATEGY_H
