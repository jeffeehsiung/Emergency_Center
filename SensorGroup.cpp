#include "headers/SensorGroup.h"


void SensorGroup::addSensor(Component& component)
{
    /** the component parameter is a reference to a Sensor component. 
     * the method adds the component to the vector of components 
     **/
    components.push_back(component);
}

void SensorGroup::removeSensor(Component& component)
{
    /** the component paramter is a reference to a Sensor component.
     * the method removes the component from the vector of components based on the component's id
    */
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i].getId() == component.getId())
        {
            components.erase(components.begin() + i);
        }
    }
}

void SensorGroup::getSensors()
{
    /** return the updated vector of components **/
    return components;
}
