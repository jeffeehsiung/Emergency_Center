#include "headers/Sensors/Smoke.h"

void Smoke::setThreshold(const int type)
{
    threshold = type;
};

int Smoke::getThreshold() {
    return threshold;
};