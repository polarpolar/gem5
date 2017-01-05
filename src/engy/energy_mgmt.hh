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

protected:
    std::string _path_energy_profile;
};

#endif //GEM5_ENGY_HH
