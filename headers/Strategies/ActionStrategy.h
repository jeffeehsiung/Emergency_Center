#pragma once
// ActionStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ACTIONSTRATEGY_H
#define ACTIONSTRATEGY_H

#include "SensorStrategy.h"

class ActionStrategy : public SensorStrategy
{
public:
    ActionStrategy(){};
    ~ActionStrategy(){};
    virtual void executeStrategy() const = 0;
};

#endif  // ACTIONSTRATEGY_H
