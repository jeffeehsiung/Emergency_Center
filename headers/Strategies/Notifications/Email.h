// Email is one of the concrete strategies under parent interface NotificationStrategy that is used by the SensorContext class.
// the Email concrete strategy class header file is shown below:
#ifndef EMAIL_H
#define EMAIL_H

#include "NotificationStrategy.h"
#include <string>
using namespace std;

class Email : public NotificationStrategy
{
public:
    Email(){};
    virtual ~Email(){};
    void executeStrategy(string receiver) const override;
};

#endif  // EMAIL_H
