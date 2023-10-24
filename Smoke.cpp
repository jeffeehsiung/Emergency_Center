#include "/headers/Sensors/Smoke.h"

void Smoke::setThreshold(const int type)
{
    threshold = type;
};

std::string Smoke::getThreshold() {
    return threshold;
};