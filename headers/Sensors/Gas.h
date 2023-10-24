#include "Sensor.h"

class Gas : public Sensor
{
    private:
        std::string gasType;
    public:
        virtual void setGasType(const std::string& type);
        virtual std::string getGasType();
};
