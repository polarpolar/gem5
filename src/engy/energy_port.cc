//
// Created by lf-z on 1/6/17.
//

#include "engy/energy_port.hh"

int MasterEnergyPort::bind_slave(SlaveEnergyPort &_slave)
{
    slave_list.push_back(&_slave);
    _slave.set_master(*this);
    return 0;
}

int SlaveEnergyPort::set_master(MasterEnergyPort &_master)
{
    master = &_master;
    return 0;
}
