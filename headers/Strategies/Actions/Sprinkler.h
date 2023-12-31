// Sprinkler is one of the concrete strategies under parent interface ActionStrategy that is used by the SensorContext class.
// the Sprinkler concrete strategy class header file is shown below:
#ifndef SPRINKLER_H
#define SPRINKLER_H

#include "../ActionStrategy.h"

class Sprinkler : public ActionStrategy
{
public:
    Sprinkler(){};
    virtual ~Sprinkler(){};
    virtual void executeStrategy() const override;
};

#endif  // SPRINKLER_H