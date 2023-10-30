// LeafAlarm is one of the concrete strategies under parent interface AlarmStrategy that is used by the SensorContext class.
// the LeafAlarm concrete strategy class header file is shown below:
//hello
#ifndef LEAFALARM_H
#define LEAFALARM_H

#include "../AlarmStrategy.h"
#include <string>

class LeafAlarm : public AlarmStrategy
{
private:
    std::string leafAlarm;
public:
    //leafAlarm constructor to specify the name of the leaf alarm
    LeafAlarm(std::string leafAlarm): leafAlarm(leafAlarm){};
    virtual ~LeafAlarm(){};
    virtual void executeStrategy() const override;
};

#endif  // LEAFALARM_H
