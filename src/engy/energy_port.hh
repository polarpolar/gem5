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
    SimObject &owner;

public:

    EnergyPort(SimObject &_owner)
            : port_id(-1), port_name(""), owner(_owner)
    { }

    void set_port_id(int _port_id)
    {
        port_id = _port_id;
    }

    void set_port_name(std::string _port_name)
    {
        port_name = _port_name;
    }

    int get_port_id()
    {
        return port_id;
    }

    std::string get_port_name()
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
    MasterEnergyPort(SimObject &_owner)
            : EnergyPort(_owner)
    {
        slave_list.resize(0);
    }

    int bind_slave(SlaveEnergyPort& _slave);

};

class SlaveEnergyPort : public EnergyPort
{
    //friend class MasterEnergyPort;
protected:
    MasterEnergyPort* master;

public:
    SlaveEnergyPort(SimObject &_owner)
            : EnergyPort(_owner), master(NULL)
    { }

    int set_master(MasterEnergyPort& _master);

};

#endif //GEM5_ENERGY_PORT_HH
