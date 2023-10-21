// Police is one of the concrete strategies under parent interface EmergencyStrategy that is used by the SensorContext class.
// the Police concrete strategy class header file is shown below:
#ifndef POLICE_H
#define POLICE_H

#include "EmergencyStrategy.h"

class Police : public EmergencyStrategy
{
public:
    Police();
    virtual ~Police();
    void executeStrategy() override;
};

#endif  // POLICE_H