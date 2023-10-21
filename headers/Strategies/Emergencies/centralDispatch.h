// CentralDispatch is one of the concrete strategies under parent interface EmergencyStrategy that is used by the SensorContext class.
// the CentralDispatch concrete strategy class header file is shown below:
#ifndef CENTRALDISPATCH_H
#define CENTRALDISPATCH_H

#include "EmergencyStrategy.h"

class CentralDispatch : public EmergencyStrategy
{
public:
    CentralDispatch();
    virtual ~CentralDispatch();
    void executeStrategy() override;
};

#endif  // CENTRALDISPATCH_H
