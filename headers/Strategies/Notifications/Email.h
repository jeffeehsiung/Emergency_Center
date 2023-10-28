// Email is one of the concrete strategies under parent interface NotificationStrategy that is used by the SensorContext class.
// the Email concrete strategy class header file is shown below:
#ifndef EMAIL_H
#define EMAIL_H

#include "../NotificationStrategy.h"
#include <string>

class Email : public NotificationStrategy
{
public:
    Email() = default;
    ~Email() = default;
    Email(std::string receipientName, std::string receipientEmail, std::string message);
    virtual void executeStrategy() const override;
private:
    std::string receipientName;
    std::string receipientEmail;
    std::string message;
};

#endif  // EMAIL_H
