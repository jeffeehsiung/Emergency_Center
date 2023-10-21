#pragma once
// NotificationStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef NOTIFICATIONSTRATEGY_H
#define NOTIFICATIONSTRATEGY_H

#include "SensorStrategy.h"
#include <string>
using namespace std;

class NotificationStrategy : public SensorStrategy
{
public:
    NotificationStrategy(){};
    ~NotificationStrategy(){};
    virtual void executeStrategy(string receiver) const = 0;
};

#endif  // NOTIFICATIONSTRATEGY_H
