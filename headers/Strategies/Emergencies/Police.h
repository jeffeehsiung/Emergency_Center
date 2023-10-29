#ifndef POLICE_H
#define POLICE_H

#include "../EmergencyStrategy.h"

class Police : public EmergencyStrategy
{
public:
    Police(){};
    virtual ~Police(){};
    virtual void executeStrategy() const override;
};

#endif  // POLICE_H
