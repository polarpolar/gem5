//
// Created by lf-z on 1/9/17.
//

#include "engy/energy_object.hh"

void EnergyObject::setSimObject(SimObject *_sim)
{
    _seport.setOwner(_sim);
    _meport.setOwner(_sim);
}
int EnergyObject::consumeEnergy(double _energy)
{
    return 1;
}

MasterEnergyPort& EnergyObject::getMasterEnergyPort()
{
    return _meport;
}

SlaveEnergyPort& EnergyObject::getSlaveEnergyPort()
{
    return _seport;
}

int EnergyObject::powerOff()
{
    return 1;
}

int EnergyObject::powerOn()
{
    return 1;
}