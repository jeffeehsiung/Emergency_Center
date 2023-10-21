// LeafAlarm is one of the concrete strategies under parent interface AlarmStrategy that is used by the SensorContext class.
// the LeafAlarm concrete strategy class header file is shown below:

#ifndef LEAFALARM_H
#define LEAFALARM_H

#include "AlarmStrategy.h"

class LeafAlarm : public AlarmStrategy
{
public:
    LeafAlarm();
    virtual ~LeafAlarm();
    void executeStrategy() override;
};

#endif  // LEAFALARM_H