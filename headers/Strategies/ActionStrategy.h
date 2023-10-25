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
    virtual void executeStrategy() const override = 0;
};

class AC : public ActionStrategy
{
public:
    AC(){};
    ~AC(){};
    virtual void executeStrategy() const override;
};

class Light : public ActionStrategy
{
public:
    Light(){};
    ~Light(){};
    virtual void executeStrategy() const override;
};

class Sprinkler : public ActionStrategy
{
public:
    Sprinkler(){};
    ~Sprinkler(){};
    virtual void executeStrategy() const override;
};

#endif  // ACTIONSTRATEGY_H
