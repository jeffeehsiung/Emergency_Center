// SMS is one of the concrete strategies under parent interface NotificationStrategy that is used by the SensorContext class.
// the SMS concrete strategy class header file is shown below:

#ifndef SMS_H
#define SMS_H

#include "NotificationStrategy.h"
#include <string>
using namespace std;

class SMS : public NotificationStrategy
{
public:
    SMS(){};
    virtual ~SMS(){};
    void executeStrategy(string receiver) const override;
};

#endif  // SMS_H