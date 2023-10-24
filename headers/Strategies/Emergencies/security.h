// Security is one of the concrete strategies under parent interface EmergencyStrategy that is used by the SensorContext class.
// the Security concrete strategy class header file is shown below:
#ifndef SECURITY_H
#define SECURITY_H

#include "headers/EmergencyStrategy.h"


class Security : public EmergencyStrategy
{
public:
    Security(){};
    ~Security(){};
    virtual void executeStrategy() const override;
};

#endif  // SECURITY_H