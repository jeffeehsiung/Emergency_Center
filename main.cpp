#include <iostream>
#include <string>
#include <EmergencyCenter.h>

int main ()
{
    // test the shared library by creating a EmergencyCenter object using the extern keyword after linking the library
    EmergencyCenter* center = EmergencyCenter::getInstance();
    // create a component
    Component* component = new Sensor();
    // add the component to the center
    center->addComponent(std::unique_ptr<Component>(component));
    // print the component
    center->printAllComponents();

    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}
