#include "headers/EmergencyCenter.h"

int main ()
{
    // test the shared library by creating a EmergencyCenter object using the extern keyword after linking the library
    EmergencyCenter* center = EmergencyCenter::getInstance();
    // create a component
    Component* m1 = new Motion("M001", "Twix galaxy", "Disney", 0, 24, true, true, 1, 0);
    SensorStrategy* pol = new Police(); 
    m1 -> addStrategy(std::shared_ptr<SensorStrategy>(pol));
    center->addComponent(std::shared_ptr<Component>(m1));

    //X AE A-12
    Component* group1 = new SensorGroup("X AE A-12");
    Component* g1 = new Gas("G001", "X AE A-12", "Disney", 0, 24, true, false, 1, "Suplhur", 1000000000);
    SensorStrategy* scientistSulphur = new SMS("Scientists", "number list","X AE A-12 has exceeded 1 billion ton of sulphur"); 
    g1 -> addStrategy(std::shared_ptr<SensorStrategy>(scientistSulphur));
    Component* s1 = new Smoke("S001", "Redstone", "Disney", 0, 24, true, false, 1, 100);
    Component* s2 = new Smoke("S002", "Orangestone", "Disney", 0, 24, true, false, 1, 100);
    SensorStrategy* magmaSprinklerRedstone = new Sprinkler(); 
    SensorStrategy* magmaSprinklerOrangestone = new Sprinkler();
    s1 -> addStrategy(std::shared_ptr<SensorStrategy>(magmaSprinklerRedstone));
    s2 -> addStrategy(std::shared_ptr<SensorStrategy>(magmaSprinklerOrangestone));
    dynamic_cast<SensorGroup*>(group1) -> addComponent(std::shared_ptr<Component>(g1));
    dynamic_cast<SensorGroup*>(group1) -> addComponent(std::shared_ptr<Component>(s1));
    dynamic_cast<SensorGroup*>(group1) -> addComponent(std::shared_ptr<Component>(s2));
    center->addComponent(std::shared_ptr<Component>(group1));
    
    //LV-426
    Component* group2 = new SensorGroup("LV-426");
    Component* g2 = new Gas("G002", "LV-426", "Bisney", 0, 24, true, false, 1, "Oxygen", 1200000000);
    SensorStrategy* lvAlarm = new LeafAlarm("Oxygen Alarm"); 
    g2 ->addStrategy(std::shared_ptr<SensorStrategy>(lvAlarm));
    Component* m2 = new Motion("M002", "LV-426", "Disney", 0, 24, true, true, 1, 0);
    SensorStrategy* scientistMotion = new SMS("Scientists", "number list","LV-426 atmosphere has been breached"); 
    m2 ->addStrategy(std::shared_ptr<SensorStrategy>(pol));
    m2 ->addStrategy(std::shared_ptr<SensorStrategy>(scientistMotion));
    dynamic_cast<SensorGroup*>(group2) -> addComponent(std::shared_ptr<Component>(g2));
    dynamic_cast<SensorGroup*>(group2) -> addComponent(std::shared_ptr<Component>(m2));
    Component* group3 = new SensorGroup("Moon Unit");
    Component* group4 = new SensorGroup("Dweezil");
    dynamic_cast<SensorGroup*>(group2) -> addComponent(std::shared_ptr<Component>(group3));
    dynamic_cast<SensorGroup*>(group2) -> addComponent(std::shared_ptr<Component>(group4));
    Component* s3 = new Smoke("S003", "Moon Unit", "Aisney", 0, 24, true, false, 1, 100);
    Component* s4 = new Smoke("S004", "Dweezil", "Disney", 0, 24, true, false, 1, 100);
    SensorStrategy* fire = new FireBrigade();
    s3 ->addStrategy(std::shared_ptr<SensorStrategy>(fire));
    s4 ->addStrategy(std::shared_ptr<SensorStrategy>(fire));
    Component* m3 = new Motion("M003", "Moon Unit", "Zisney", 20, 8, true, false, 1, 10);
    Component* m4 = new Motion("M004", "Dweezil", "Lisney", 20, 8, true, false, 1, 10);
    SensorStrategy* eggs = new SMS("Zorglax", "HQ number","Eggs are hatching"); 
    m3 ->addStrategy(std::shared_ptr<SensorStrategy>(eggs));
    m4 ->addStrategy(std::shared_ptr<SensorStrategy>(eggs));
    dynamic_cast<SensorGroup*>(group3) -> addComponent(std::shared_ptr<Component>(s3));
    dynamic_cast<SensorGroup*>(group3) -> addComponent(std::shared_ptr<Component>(m3));
    dynamic_cast<SensorGroup*>(group4) -> addComponent(std::shared_ptr<Component>(s4));
    dynamic_cast<SensorGroup*>(group4) -> addComponent(std::shared_ptr<Component>(m4));
    center->addComponent(std::shared_ptr<Component>(group2));

    // center->printAllComponents();
    center->deactivateAllComponents(0);
    center->activateAllComponents(1); // 1 is Gas sensors, 2 is Motion , 3 is Smoke and 0 is all
    center->testAllComponents(1);
    center->activateComponent(group1, 0);
    center->testComponent(group1,0);
    center->deactivateComponent(group2, 0);
    center->testComponent(group2, 0);
    center->activateComponent(group2, 0);

    // center->deactivateAllComponents(0);
    // center->testAllComponents(0);
    // center->activateAllComponents(0);
    // center->testAllComponents(0);
    // print in console that the following is the orderby functions
    std::cout << "Orderby ID functions" << std::endl;
    center->orderByComponentId();
    std::cout<<*center;
    std::cout << "Orderby Vendor functions" << std::endl;
    center->orderByComponentVendor();
    std::cout<<*center;
    std::cout << "Orderby Location functions" << std::endl;
    center->orderByComponentLocation();
    std::cout<<*center;


    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}
