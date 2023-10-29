#pragma once
// ActionStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ACTIONSTRATEGY_H
#define ACTIONSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class ActionStrategy : public SensorStrategy
{
public:
    virtual void executeStrategy() const override = 0;
};

#endif  // ACTIONSTRATEGY_H
