#include "headers/EmergencyCenter.h"

int main ()
{
    // test the shared library by creating a EmergencyCenter object using the extern keyword after linking the library
    EmergencyCenter* center = EmergencyCenter::getInstance();
    // create a component
    Component* comp1 = new Smoke("S001", "labChemistry", "Sensor Solution", 0, 24, true, false, 0, 1, 100);
    Component* comp2 = new Gas("G001", "labChemistry", "GasSense", 0, 24, true, false, 0, 1, "NOx");
    //Component* component = new SensorGroup("5.01", 0, 24, true, false, 0);
    //component->addSensor(std::shared_ptr<Component>(comp1));
    // add the component to the center
    center->addComponent(std::unique_ptr<Component>(comp1));
    center->addComponent(std::unique_ptr<Component>(comp2));
    SensorStrategy* strat1 = new CentralDispatch(); 
    SensorStrategy* strat2 = new Email("Lore Hennebel", "lore.hennebel@kuleuven.be", "Gas sensor activated");
    // print the component
    center->printAllComponents();

    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}
