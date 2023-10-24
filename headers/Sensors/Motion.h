#include "Sensor.h"

class Motion : public Sensor
{
    private:
        int activationRange;
    public:
        virtual void setActivationRange();
        virtual int getActivationRange();
};
