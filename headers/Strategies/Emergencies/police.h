#ifndef POLICE_H
#define POLICE_H

#include "EmergencyStrategy.h"
#include <iostream>

class Police : public EmergencyStrategy
{
public:
    Police();
    virtual ~Police();
    void executeStrategy() const override;
};

#endif  // POLICE_H
