//
// Created by lf-z on 12/28/16.
//

#include "engy/energy_mgmt.hh"
#include "debug/EnergyMgmt.hh"

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
    DPRINTF(EnergyMgmt, "Energy Management module initialized!\n");
    DPRINTF(EnergyMgmt, "Energy profile: %s\n", _path_energy_profile.c_str());
    //printf("Energy Management module initialized!\n");
    //printf("Energy profile: %s\n", _path_energy_profile.c_str());
}

int EnergyMgmt::consumeEnergy(double val)
{
    /* Todo: Pass the module which consumed the energy to this function. (Or DPRINTF in the module which consumes energy) */
    DPRINTF(EnergyMgmt, "Energy %lf is consumed by xxx. Energy remained: xxx\n", val);
    return 1;
}

void EnergyMgmt::broadcastPowerOff()
{
    EnergyMsg msg;
    msg.type = POWEROFF;
    _meport.broadcastMsg(msg);
    DPRINTF(EnergyMgmt, "Insufficient energy, system power off.\n");
}

void EnergyMgmt::broadcastPowerOn()
{
    EnergyMsg msg;
    msg.type = POWERON;
    _meport.broadcastMsg(msg);
    DPRINTF(EnergyMgmt, "Sufficient energy, system power on.\n");
}

EnergyMgmt *
EnergyMgmtParams::create()
{
    return new EnergyMgmt(this);
}
