// AC is one of the concrete strategies under parent interface ActionStrategy that is used by the SensorContext class.
// the AC concrete strategy class header file is shown below:
#ifndef AC_H
#define AC_H

#include "ActionStrategy.h"

class AC : public ActionStrategy
{
public:
    AC(){};
    ~AC(){};
    virtual void executeStrategy() const override;
};

#endif  // AC_H