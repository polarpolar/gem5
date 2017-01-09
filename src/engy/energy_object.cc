//
// Created by lf-z on 1/9/17.
//

#include "engy/energy_object.hh"

int EnergyObject::consumeEnergy(double _energy)
{
    return _seport.consumeEnergy(_energy);
}

int EnergyObject::powerOff()
{
    return 0;
}

int EnergyObject::powerOn()
{
    return 0;
}