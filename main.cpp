#include "headers/EmergencyCenter.h"

int main ()
{
    EmergencyCenter* center = EmergencyCenter::getInstance();

    // Lab Chemistry 5.01
    Component* chemSmokeSensor = new Smoke("S001", "5.01", "Sensor Solution", 0, 24, false, false, 1, 100);
    Component* chemGasSensor = new Gas("G001", "5.01", "GasSense", 0, 24, true, false, 1, "NOx");
    center->addComponent(std::unique_ptr<Component>(chemSmokeSensor));
    center->addComponent(std::unique_ptr<Component>(chemGasSensor));

    SensorStrategy* centralDispatch = new CentralDispatch(); 
    SensorStrategy* loreEmail = new Email("Lore Hennebel", "lore.hennebel@kuleuven.be", "Gas sensor activated");
    chemSmokeSensor->addStrategy(std::shared_ptr<SensorStrategy>(centralDispatch));
    chemGasSensor->addStrategy(std::shared_ptr<SensorStrategy>(loreEmail));

    // Lab Electronics 10.01
    Component* elecSmokeSensor = new Smoke("S002", "10.01", "Sensor Solution", 0, 24, false, false, 1, 100);
    Component* motionSensor10_01 = new Motion("M001", "10.01", "GotYou", 22, 7, true, false, 1);  // Active between 10pm and 7am
    center->addComponent(std::unique_ptr<Component>(elecSmokeSensor));
    center->addComponent(std::unique_ptr<Component>(motionSensor10_01));

    SensorStrategy* gertSMS = new SMS("Gert Vanloock", "Gas sensor activated");
    elecSmokeSensor->addStrategy(std::shared_ptr<SensorStrategy>(centralDispatch));
    motionSensor10_01->addStrategy(std::shared_ptr<SensorStrategy>(gertSMS));

    // Lab Electronics 10.02
    Component* motionSensor10_02 = new Motion("M002", "10.02", "GotYou", 22, 7, true, false, 1);  // Active between 10pm and 7am
    center->addComponent(std::unique_ptr<Component>(motionSensor10_02));
    motionSensor10_02->addStrategy(std::shared_ptr<SensorStrategy>(gertSMS));

    // Alma kitchen 1.03
    Component* almaSmokeSensor = new Smoke("S003", "1.03", "KitchenSafe", 0, 24, false, false, 1, 100);
    Component* almaGasSensor = new Gas("G002", "1.03", "GasSense", 0, 24, true, false, 1, "CO");
    Component* almaMotionSensor = new Motion("M003", "1.03", "BigBrother Is Watching You", 0, 24, true, false, 1);
    center->addComponent(std::unique_ptr<Component>(almaSmokeSensor));
    center->addComponent(std::unique_ptr<Component>(almaGasSensor));
    center->addComponent(std::unique_ptr<Component>(almaMotionSensor));

    SensorStrategy* extinctionSystem = new ExtinctionSystem();
    SensorStrategy* localAlarm = new LocalAlarm();
    SensorStrategy* policeAndSecurity = new PoliceAndSecurity();
    almaSmokeSensor->addStrategy(std::shared_ptr<SensorStrategy>(extinctionSystem));
    almaGasSensor->addStrategy(std::shared_ptr<SensorStrategy>(localAlarm));
    almaMotionSensor->addStrategy(std::shared_ptr<SensorStrategy>(policeAndSecurity));

    // TODO: Implement the remaining actions like activating, testing sensors, and ordering by vendor.
    // The provided code has some example actions that you can use as reference.

    std::cout << "End of the program" << std::endl;

    return 0;
}
