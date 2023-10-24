#include "/headers/Sensors/Gas.h"

void Gas::setGasType(const std::string& type)
{
    gasType = type;
};

std::string Gas::getGasType() {
    return gasType;
};