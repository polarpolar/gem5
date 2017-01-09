//
// Created by lf-z on 1/6/17.
//

#include "engy/energy_port.hh"

int MasterEnergyPort::bindSlave(SlaveEnergyPort &_slave)
{
    slave_list.push_back(&_slave);
    _slave.setMaster(*this);
    return 0;
}

int MasterEnergyPort::consumeEnergy(double _energy)
{
    return 0;
}

int SlaveEnergyPort::setMaster(MasterEnergyPort &_master)
{
    master = &_master;
    return 0;
}

int SlaveEnergyPort::consumeEnergy(double _energy)
{
    return master->consumeEnergy(_energy);
}