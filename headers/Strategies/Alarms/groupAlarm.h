// GroupAlarm is one of the concrete strategies under parent interface AlarmStrategy that is used by the SensorContext class.
// the GroupAlarm concrete strategy class header file is shown below:
#ifndef GROUPALARM_H
#define GROUPALARM_H

#include "AlarmStrategy.h"

class GroupAlarm : public AlarmStrategy
{
public:
    GroupAlarm();
    virtual ~GroupAlarm();
    void executeStrategy() override;
};

#endif  // GROUPALARM_H

