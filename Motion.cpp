#include "headers/Sensor.h"

void Motion::setActivationRange(const int type)
{
    activationRange = type;
};

int Motion::getActivationRange() {
    return activationRange;
};