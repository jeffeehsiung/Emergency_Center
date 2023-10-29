#include "headers/EmergencyCenter.h"

int main ()
{
    // test the shared library by creating a EmergencyCenter object using the extern keyword after linking the library
    EmergencyCenter* center = EmergencyCenter::getInstance();
    /** create sensorgoup rooms */
    Component* shed = new SensorGroup("Shed");
    Component* kitchen = new SensorGroup("Kitchen");
    Component* livingRoom = new SensorGroup("Living Room");
    Component* lab = new SensorGroup("Lab");
    Component* residential = new SensorGroup("Residential");

    /** John is a carpenter and has some machinery in his shed. A smoke sensor of the brand Smokey is
     * definitely needed here. Also add a motion sensor of the brand IcanCU. The actions for the smoke
     * sensor is activating the house alarm and send a message to Fire department of the
     * neighborhood. The motion sensor should activate the light and send an turn on the air
     * conditioner. 
     * */
    // create components
    Component* s1 = new Smoke("S001", "Smokey", "John", 0, 24, true, false, 1, 100);
    Component* m1 = new Motion("M001", "IcanCU", "John", 0, 24, true, true, 1, 0);
    // create strategies
    SensorStrategy* houseAlarm1 = new LeafAlarm("House Alarm");
    SensorStrategy* fireDepartment1 = new FireBrigade();
    SensorStrategy* light1 = new Light();
    SensorStrategy* ac1 = new AC();
    // add strategies to components
    s1 -> addStrategy(std::shared_ptr<SensorStrategy>(houseAlarm1));
    s1 -> addStrategy(std::shared_ptr<SensorStrategy>(fireDepartment1));
    m1 -> addStrategy(std::shared_ptr<SensorStrategy>(light1));
    m1 -> addStrategy(std::shared_ptr<SensorStrategy>(ac1));
    // add components to shed
    dynamic_cast<SensorGroup*>(shed) -> addComponent(std::shared_ptr<Component>(s1));
    dynamic_cast<SensorGroup*>(shed) -> addComponent(std::shared_ptr<Component>(m1));

    /** Vicky is John’s wife and she likes to cook, every kitchen of course needs a smoke sensor from the
     * brand Smokey and a motion sensor from IcanCU. The actions for the smoke sensor are the same
     * as the one in the shed. The motion sensor should only be active between 10pm and 7am, if
     * activated it should send an email to vicky at vicky.cooke@gmail.com.
     * */
    // create components
    Component* s2 = new Smoke("S002", "Smokey", "Vicky", 0, 24, true, false, 1, 100);
    Component* m2 = new Motion("M002", "IcanCU", "Vicky", 7, 22, true, false, 1, 0);
    // create strategies
    SensorStrategy* houseAlarm2 = new LeafAlarm("House Alarm");
    SensorStrategy* fireDepartment2 = new FireBrigade();
    SensorStrategy* email1 = new Email("Vicky", "vicky.cooke@gmail.com", "Motion sensor activated");
    // add strategies to components
    s2 -> addStrategy(std::shared_ptr<SensorStrategy>(houseAlarm2));
    s2 -> addStrategy(std::shared_ptr<SensorStrategy>(fireDepartment2));
    m2 -> addStrategy(std::shared_ptr<SensorStrategy>(email1));
    // add components to kitchen
    dynamic_cast<SensorGroup*>(kitchen) -> addComponent(std::shared_ptr<Component>(s2));
    dynamic_cast<SensorGroup*>(kitchen) -> addComponent(std::shared_ptr<Component>(m2));

    /** Dave has an old fireplace in his living room. These need a carbon monoxide sensor from
     * BreatheLabs and a smoke sense from BurningInc. The smoke sensor activates the sprinkler
     * system and sends a message to the fire department of the neighborhood. The CO sensor sets off
     * the alarm of the house.
     * */
    // create components
    Component* s3 = new Smoke("S003", "BurningInc", "Dave", 0, 24, true, false, 1, 100);
    Component* g1 = new Gas("G001", "BreatheLabs", "Dave", 0, 24, true, false, 1, "Carbon Monoxide", 1000000000);
    // create strategies
    SensorStrategy* houseAlarm3 = new LeafAlarm("House Alarm");
    SensorStrategy* fireDepartment3 = new FireBrigade();
    SensorStrategy* sprinkler1 = new Sprinkler();
    // add strategies to components
    s3 -> addStrategy(std::shared_ptr<SensorStrategy>(sprinkler1));
    s3 -> addStrategy(std::shared_ptr<SensorStrategy>(fireDepartment3));
    g1 -> addStrategy(std::shared_ptr<SensorStrategy>(houseAlarm3));
    // add components to living room
    dynamic_cast<SensorGroup*>(livingRoom) -> addComponent(std::shared_ptr<Component>(s3));
    dynamic_cast<SensorGroup*>(livingRoom) -> addComponent(std::shared_ptr<Component>(g1));

    /** Then there is also Kaitlin… She is the evil scientist who likes to do experiments at home. A gas
     * sensor from TN2S is installed in her house. If this sensor goes off the whole neighborhood has to
     * be evacuated due to danger of explosion. All alarms in all houses should be activated. Kaitlin also
     * has a motion sensor of the brand IcanCU in her lab that sends an email if motion is detected
     * between 4:40 and 9:15, since this is the time that the mad scientist sleeps.
     * */
    // create components
    Component* g2 = new Gas("G002", "TN2S", "Kaitlin", 0, 24, true, false, 1, "Methane", 1000000000);
    Component* m3 = new Motion("M003", "IcanCU", "Kaitlin", 4, 9, true, false, 1, 0);
    // create strategies
    SensorStrategy* houseAlarm4 = new GroupAlarm("House Alarm");
    SensorStrategy* dispatch1 = new CentralDispatch();
    SensorStrategy* email2 = new Email("Kaitlin", "katlinlab@gmail.com", "Motion sensor activated");
    // add strategies to components
    g2 -> addStrategy(std::shared_ptr<SensorStrategy>(houseAlarm4));
    g2 -> addStrategy(std::shared_ptr<SensorStrategy>(dispatch1));
    m3 -> addStrategy(std::shared_ptr<SensorStrategy>(email2));
    // add components to lab
    dynamic_cast<SensorGroup*>(lab) -> addComponent(std::shared_ptr<Component>(g2));
    dynamic_cast<SensorGroup*>(lab) -> addComponent(std::shared_ptr<Component>(m3));

    /** add all the rooms to each of the houses */
    // John and Vicky's house to jvhouse
    Component* jvhouse = new SensorGroup("John and Vicky's House");
    dynamic_cast<SensorGroup*>(jvhouse) -> addComponent(std::shared_ptr<Component>(shed));
    dynamic_cast<SensorGroup*>(jvhouse) -> addComponent(std::shared_ptr<Component>(kitchen));
    // Dave's house to dhouse
    Component* dhouse = new SensorGroup("Dave's House");
    dynamic_cast<SensorGroup*>(dhouse) -> addComponent(std::shared_ptr<Component>(livingRoom));
    // Kaitlin's house to khouse
    Component* khouse = new SensorGroup("Kaitlin's House");
    dynamic_cast<SensorGroup*>(khouse) -> addComponent(std::shared_ptr<Component>(lab));

    /** add all houses to residentail group */
    dynamic_cast<SensorGroup*>(residential) -> addComponent(std::shared_ptr<Component>(jvhouse));
    dynamic_cast<SensorGroup*>(residential) -> addComponent(std::shared_ptr<Component>(dhouse));
    dynamic_cast<SensorGroup*>(residential) -> addComponent(std::shared_ptr<Component>(khouse));

    /** add all houses to Emergency Center */
    center->addComponent(std::shared_ptr<Component>(residential));

    /** default print all compoenents and deactivate all components */
    center->printAllComponents();
    center->deactivateAllComponents(0);

    /** Activate and test the smoke sensor in shed */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Activate and test the smoke sensor in shed" << std::endl;
    center->activateComponent(shed, 0);
    center->testComponent(shed,0);
    std::cout << "------------------------------------------" << std::endl;

    /** Activate adn test all sensors in Vicky and John's house */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Activate adn test all sensors in Vicky and John's house" << std::endl;
    center->activateComponent(jvhouse, 0);
    center->testComponent(jvhouse,0);
    std::cout << "------------------------------------------" << std::endl;

    /** Test all sensors in the neighborhood 
     * same result as previous since all other sensors are still deactivated 
     * */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test all sensors in the neighborhood" << std::endl;
    std::cout << "(same result as previous since all other sensors are still deactivated)" << std::endl;
    center->testComponent(residential,0);
    std::cout << "------------------------------------------" << std::endl;

    /** Activate all sensors using the ++ operator */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Activate all sensors using the ++ operator" << std::endl;
    std::cout << "(++ operator is used in activateAllComponents(Component* component, int mode) ) " << std::endl;
    center->activateAllComponents(0); // 1 is Gas sensors, 2 is Motion , 3 is Smoke and 0 is all
    std::cout << "------------------------------------------" << std::endl;

    /** Test the whole neighborhood */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test the whole neighborhood" << std::endl;
    center->testComponent(residential,0);
    std::cout << "------------------------------------------" << std::endl;

    /** Test the mad scientist’s house */
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test the mad scientist’s house" << std::endl;
    center->testComponent(khouse,0);
    std::cout << "------------------------------------------" << std::endl;

    /** Give an overview of all sensors ordered by id */
    std::cout << "Orderby ID functions" << std::endl;
    center->orderByComponentId();
    std::cout<<*center;


    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}

