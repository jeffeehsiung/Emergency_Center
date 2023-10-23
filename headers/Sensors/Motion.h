#include "Sensor.h"

class Motion : public Sensor
{
    private:
        int activationRange;
    public:
        virtual void setactivationRange();
        virtual int getactivationRange();
};
