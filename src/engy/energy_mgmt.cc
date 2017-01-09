//
// Created by lf-z on 12/28/16.
//

#include "engy/energy_mgmt.hh"

EnergyMgmt::EnergyMgmt(const Params *p)
        : SimObject(p),
          _path_energy_profile(p->path_energy_profile),
          event_poweroff(this),
          event_poweron(this)
{

}

EnergyMgmt::~EnergyMgmt()
{

}

void EnergyMgmt::init()
{
    /* Todo: Read energy profile here */
    printf("Energy Management module initialized!\n");
    printf("Energy profile: %s\n", _path_energy_profile.c_str());
}

int EnergyMgmt::consumeEnergy(double val)
{
    return 1;
}

void EnergyMgmt::broadcastPowerOff()
{
    EnergyMsg msg;
    msg.type = POWEROFF;
    _meport.broadcastMsg(msg);
}

void EnergyMgmt::broadcastPowerOn()
{
    EnergyMsg msg;
    msg.type = POWERON;
    _meport.broadcastMsg(msg);
}

EnergyMgmt *
EnergyMgmtParams::create()
{
    return new EnergyMgmt(this);
}
