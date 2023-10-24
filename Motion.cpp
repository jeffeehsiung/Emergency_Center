#include "/headers/Sensors/Motion.h"

void Motion::setActivationRange(const int type)
{
    activationRange = type;
};

std::string Motion::getActivationRange() {
    return activationRange;
};