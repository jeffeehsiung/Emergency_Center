#include "Sensor.h"

class Smoke : public Sensor
{
    private:
        int threshold;
    public:
        virtual void setThreshold();
        virtual int getThreshold();
};
