#include "headers/Strategies/ActionStrategy.h"

void AC::executeStrategy() const
{
    std::cout << "Turn on the air conditioner\n" << std::endl;
}

void Light::executeStrategy() const
{
    std::cout << "Turning on the light \n" << std::endl;
}

void Sprinkler::executeStrategy() const
{
    //print "activate the sprinkler system"
    std::cout << "activate the sprinkler system \n" << std::endl;
}