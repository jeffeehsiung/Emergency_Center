#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component {
protected:
    std::string id;
    std::string location;
    bool isActive;
    // To be added more...

public:
    virtual ~Component() {}  // Virtual destructor

    // Getter and setter functions for the attributes
    std::string getId() const;
    void setId(const std::string& id);

    std::string getLocation() const;
    void setLocation(const std::string& location);

    bool getIsActive() const;
    void setIsActive(bool isActive);

    // To be added more...
};

#endif // COMPONENT_H
