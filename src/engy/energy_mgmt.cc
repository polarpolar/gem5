//
// Created by lf-z on 12/28/16.
//
#include <fstream>
#include "engy/energy_mgmt.hh"
#include "debug/EnergyMgmt.hh"

EnergyMgmt::EnergyMgmt(const Params *p)
        : SimObject(p),
          _path_energy_profile(p->path_energy_profile),
          _time_unit(p->energy_time_unit),
          event_poweroff(this),
          event_poweron(this)
{

}

EnergyMgmt::~EnergyMgmt()
{

}

void EnergyMgmt::init()
{
    /* Read energy profile */
    std::vector<double> energy_data;
    energy_data = read_energy_profile();

    /* Todo: Push energy harvesting events here */
    push_energy_harvesting_events(energy_data);

    DPRINTF(EnergyMgmt, "Energy Management module initialized!\n");
    DPRINTF(EnergyMgmt, "Energy profile: %s (Time unit: %d ticks)\n",
            _path_energy_profile.c_str(), _time_unit);
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

std::vector<double> EnergyMgmt::read_energy_profile()
{
    std::vector<double> data;
    double temp;
    std::ifstream fin;
    fin.open(_path_energy_profile.c_str());
    /* Todo: read energy profile and store the data into vector. */
    data.resize(0);
    while (fin>>temp) {
        data.push_back(temp);
    }
    fin.close();
    return data;
}

void EnergyMgmt::push_energy_harvesting_events(std::vector<double> _energy_harv)
{
    /* Todo: push energy harvesting events into event queue */
}

EnergyMgmt *
EnergyMgmtParams::create()
{
    return new EnergyMgmt(this);
}
