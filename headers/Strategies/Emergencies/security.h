// Security is one of the concrete strategies under parent interface EmergencyStrategy that is used by the SensorContext class.
// the Security concrete strategy class header file is shown below:
#ifndef SECURITY_H
#define SECURITY_H

#include "EmergencyStrategy.h"

class Security : public EmergencyStrategy
{
public:
    Security();
    virtual ~Security();
    void executeStrategy() override;
};

#endif  // SECURITY_H