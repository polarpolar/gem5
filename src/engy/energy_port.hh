//
// Created by lf-z on 1/6/17.
//

#ifndef GEM5_ENERGY_PORT_HH
#define GEM5_ENERGY_PORT_HH

#include "sim/sim_object.hh"

class EnergyPort
{
protected:

    int port_id;
    std::string port_name;

    // owner needs to be set when SimObject is initialized.
    SimObject *owner;

public:

    EnergyPort(SimObject *_owner)
            : port_id(-1), port_name(""), owner(_owner)
    { }

    void setOwner(SimObject *_owner)
    {
        owner = _owner;
    }

    void setPortId(int _port_id)
    {
        port_id = _port_id;
    }

    void setPortName(std::string _port_name)
    {
        port_name = _port_name;
    }

    int getPortId()
    {
        return port_id;
    }

    std::string getPortName()
    {
        return port_name;
    }
};

class SlaveEnergyPort;

class MasterEnergyPort : public EnergyPort
{
    //friend class SlaveEnergyPort;
protected:
    std::vector<SlaveEnergyPort*> slave_list;

public:
    MasterEnergyPort(SimObject *_owner)
            : EnergyPort(_owner)
    {
        slave_list.resize(0);
    }

    int bindSlave(SlaveEnergyPort& _slave);
    int consumeEnergy(double _energy);

};

class SlaveEnergyPort : public EnergyPort
{
    //friend class MasterEnergyPort;
protected:
    MasterEnergyPort* master;

public:
    SlaveEnergyPort(SimObject *_owner)
            : EnergyPort(_owner), master(NULL)
    { }

    int setMaster(MasterEnergyPort& _master);
    int consumeEnergy(double _energy);

};

#endif //GEM5_ENERGY_PORT_HH
