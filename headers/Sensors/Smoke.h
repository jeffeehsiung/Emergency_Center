#include "../Sensor.h"

class Smoke : public Sensor
{
    using Sensor::Sensor;
    private:
        int threshold;
    public:
        virtual void setThreshold(const int type);
        virtual int getThreshold();
};
