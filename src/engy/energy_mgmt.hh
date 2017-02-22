//
// Created by lf-z on 12/28/16.
//

#ifndef GEM5_ENGY_HH
#define GEM5_ENGY_HH

#include "sim/sim_object.hh"
#include "params/EnergyMgmt.hh"

class EnergyMgmt : public SimObject
{
public:
    typedef EnergyMgmtParams Params;
    const Params *params() const
    {
        return reinterpret_cast<const Params *>(_params);
    }
    EnergyMgmt(const Params *p);
    virtual ~EnergyMgmt();
    virtual void init();
    /* Harvest energy if val < 0 */
    virtual int consumeEnergy(double val);
    void broadcastPowerOff();
    void broadcastPowerOn();

protected:
    /* Todo: there should be event wrapper for energy harvest. */
    int time_unit;
    double energy_remained;
    EventWrapper<EnergyMgmt, &EnergyMgmt::broadcastPowerOff> event_poweroff;
    EventWrapper<EnergyMgmt, &EnergyMgmt::broadcastPowerOn> event_poweron;
    std::vector<double> energy_harvest_data;
    void energyHarvest();
    EventWrapper<EnergyMgmt, &EnergyMgmt::energyHarvest> event_energy_harvest;

private:
    std::vector<double> readEnergyProfile();
    std::string _path_energy_profile;

};

#endif //GEM5_ENGY_HH
