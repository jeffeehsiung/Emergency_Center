#pragma once
// AlarmStrategy concrete SensorStrategy strategy interface implementation header file.
#ifndef ALARMSTRATEGY_H
#define ALARMSTRATEGY_H

#include "../SensorStrategy.h"
#include <iostream>

class AlarmStrategy : public SensorStrategy
{
public:
    virtual ~AlarmStrategy() = default; // the derived class can rely on the base class destructor.
    virtual void executeStrategy() const override = 0;
};

class GroupAlarm : public AlarmStrategy
{
private:
    std::string groupAlarm;
public:
    //groupAlarm constructor to specify the name of the group alarm
    GroupAlarm(std::string& groupAlarm): groupAlarm(groupAlarm){};
    virtual void executeStrategy() const override;
};

class LeafAlarm : public AlarmStrategy
{
private:
    std::string leafAlarm;
public:
    //leafAlarm constructor to specify the name of the leaf alarm
    LeafAlarm(std::string& leafAlarm): leafAlarm(leafAlarm){};
    virtual void executeStrategy() const override;
};

#endif  // ALARMSTRATEGY_H
