// SMS is one of the concrete strategies under parent interface NotificationStrategy that is used by the SensorContext class.
// the SMS concrete strategy class header file is shown below:

#ifndef SMS_H
#define SMS_H

#include "NotificationStrategy.h"
#include <string>

class SMS : public NotificationStrategy
{
public:
    SMS(std::string& receipientName, std::string& receipientNumber, std::string& message): receipientName(receipientName), receipientNumber(receipientNumber), message(message){};
    virtual void executeStrategy() const override;
private:
    std::string receipientName;
    std::string receipientNumber;
    std::string message;
};
#endif  // SMS_H