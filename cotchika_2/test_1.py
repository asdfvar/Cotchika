#!/usr/bin/python3

import numpy as np
import common

domain      = np.zeros ((10, 10))
start       = np.array ((1, 1))
destination = np.array ((8, 8))

domain[3, 3] = -1.0
domain[2, 4] = -1.0

cost = common.find_path (domain, start, destination)

print (cost)
