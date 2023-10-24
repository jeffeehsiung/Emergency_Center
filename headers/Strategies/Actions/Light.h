// Light is one of the concrete strategies under parent interface ActionStrategy that is used by the SensorContext class.
// the Light concrete strategy class header file is shown below:
#ifndef LIGHT_H
#define LIGHT_H

#include "headers/ActionStrategy.h"

class Light : public ActionStrategy
{
public:
    Light(){};
    ~Light(){};
    virtual void executeStrategy() const override;
};

#endif  // LIGHT_H