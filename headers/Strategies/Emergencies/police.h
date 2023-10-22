#ifndef POLICE_H
#define POLICE_H

#include "EmergencyStrategy.h"

class Police : public EmergencyStrategy
{
public:
    Police(){};
    ~Police(){};
    void executeStrategy() const override;
};

#endif  // POLICE_H
