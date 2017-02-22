# Created by Lefan Zhang on Feb. 22, 2017
# This file includes useful functions to config energy manage
# module in the system.

import m5
from m5.defines import buildEnv
from m5.objects import *
from Benchmarks import *

import CpuConfig
import MemConfig

from FSConfig import os_types

def connectEngyModule(opt):
    modules = opt.split()
    if 'cpu' in modules:
        print "cpu engy"
    if 'mem' in modules:
        print "mem engy"