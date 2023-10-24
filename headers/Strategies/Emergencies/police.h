#ifndef POLICE_H
#define POLICE_H

#include "headers/EmergencyStrategy.h"

class Police : public EmergencyStrategy
{
public:
    Police(){};
    ~Police(){};
    virtual void executeStrategy() const override;
};

#endif  // POLICE_H
