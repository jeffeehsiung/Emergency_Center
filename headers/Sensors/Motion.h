#include "../Sensor.h"

class Motion : public Sensor
{
    using Sensor::Sensor;
    private:
        int activationRange;
    public:
        virtual void setActivationRange(const int type);
        virtual int getActivationRange();
};
