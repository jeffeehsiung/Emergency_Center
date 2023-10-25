#pragma once
// ActionStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ACTIONSTRATEGY_H
#define ACTIONSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class ActionStrategy : public SensorStrategy
{
public:
    virtual ~ActionStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() const = 0;
};

#endif  // ACTIONSTRATEGY_H
