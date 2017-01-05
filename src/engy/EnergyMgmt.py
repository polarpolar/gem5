from m5.SimObject import SimObject
from m5.params import *
from m5.proxy import *

class EnergyMgmt(SimObject):
    type = 'EnergyMgmt'
    cxx_header = "engy/energy_mgmt.hh"
    path_energy_profile = Param.String(Parent.path_energy_profile, "path to energy profile")