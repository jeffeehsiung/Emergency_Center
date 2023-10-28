#include "headers/EmergencyCenter.h"

int main ()
{
    // test the shared library by creating a EmergencyCenter object using the extern keyword after linking the library
    EmergencyCenter* center = EmergencyCenter::getInstance();
    // create a component
    Component* comp1 = new Smoke("S001", "aabChemistry", "Aensor Solution", 0, 24, false, false, 1, 100);
    Component* comp2 = new Gas("G001", "cabChemistry", "GasSenseck", 0, 24, true, false, 1, "NOx");
    Component* comp5 = new Gas("G002", "babChemistry", "ZasSense", 0, 24, false, false, 1, "NOx");
    Component* comp6 = new Gas("G003", "dabChemistry", "BasSense", 0, 24, true, false, 1, "NOx");
    //Component* component = new SensorGroup("5.01", 0, 24, true, false, 0);
    //component->addSensor(std::shared_ptr<Component>(comp1));
    // add the component to the center
    center->addComponent(std::unique_ptr<Component>(comp1));
    center->addComponent(std::unique_ptr<Component>(comp2));
    SensorStrategy* strat1 = new CentralDispatch(); 
    SensorStrategy* strat2 = new Email("Lore Hennebel", "lore.hennebel@kuleuven.be", "Gas sensor activated");
    SensorStrategy* strat3 = new SMS("Lore Hennebel", "0477777777", "Gas sensor activated");

    Component* comp3 = new SensorGroup("5.01");
    dynamic_cast<SensorGroup*>(comp3) -> addComponent(std::shared_ptr<Component>(comp5));
    dynamic_cast<SensorGroup*>(comp3) -> addComponent(std::shared_ptr<Component>(comp6));
    center->addComponent(std::unique_ptr<Component>(comp3));
    // print the component
    comp1 -> addStrategy(std::shared_ptr<SensorStrategy>(strat1));
    comp2 -> addStrategy(std::shared_ptr<SensorStrategy>(strat2));
    comp2 -> addStrategy(std::shared_ptr<SensorStrategy>(strat3));
    comp1 -> executeStrategy();
    comp2 -> executeStrategy();
    // center->printAllComponents();
    // center->deactivateAllComponents(0);
    // center->testAllComponents(0);
    // center->activateAllComponents(0);
    // center->testAllComponents(0);
    center->orderByComponentId();
    std::cout<<*center;
    center->orderByComponentVendor();
    std::cout<<*center;
    center->orderByComponentLocation();
    std::cout<<*center;


    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}
