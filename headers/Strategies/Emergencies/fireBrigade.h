// fireBrigade is one of the concrete strategies under parent interface EmergencyStrategy that is used by the SensorContext class.
// the fireBrigade concrete strategy class header file is shown below:

#ifndef FIREBRIGADE_H
#define FIREBRIGADE_H

#include "EmergencyStrategy.h"


class FireBrigade : public EmergencyStrategy
{
public:
    FireBrigade(){};
    virtual ~FireBrigade(){};
    void executeStrategy() const override;
};

#endif  // FIREBRIGADE_H