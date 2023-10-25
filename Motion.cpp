#include "headers/Sensors/Motion.h"

void Motion::setActivationRange(const int type)
{
    activationRange = type;
};

int Motion::getActivationRange() {
    return activationRange;
};