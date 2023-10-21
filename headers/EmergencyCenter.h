#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "Sensor.h"

class EmergencyCenter
{
protected:
    //Singleton so the constructor should be private or protected
    EmergencyCenter();
    static EmergencyCenter* ec_instance;

public:
    static EmergencyCenter* GetInstance();

private:

};

#endif // EMERGENCYCENTER_H
