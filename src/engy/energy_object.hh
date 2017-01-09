//
// Created by lf-z on 1/9/17.
//

#ifndef GEM5_ENERGY_OBJECT_HH
#define GEM5_ENERGY_OBJECT_HH

#include "engy/energy_port.hh"

class EnergyObject
{
protected:
    // An energy object can be both consumer or provider,
    // so we have both slave port and master port.
    SlaveEnergyPort _seport;
    MasterEnergyPort _meport;
public:

    // A method telling energy mgmt module this object has consume energy.
    int consumeEnergy(double _energy);

    // Methods to implement actions taken when power on/off by child classes.
    virtual int powerOn();
    virtual int powerOff();
};
#endif //GEM5_ENERGY_OBJECT_HH
