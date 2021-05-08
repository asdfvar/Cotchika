#!/usr/bin/python3

import numpy as np
import common
from matplotlib import pyplot as plt

domain      = np.ones ((10, 10), dtype = bool)
resistance  = np.zeros ((10, 10))
start       = (1, 1)
destination = (8, 8)

domain[2, 4] = -1.0

domain[1, 3] = False
domain[2, 3] = False
domain[3, 3] = False
domain[3, 2] = False
domain[3, 1] = False

resistance[7, 3] = 1.0
resistance[6, 3] = 1.0
resistance[6, 4] = 1.0
resistance[6, 5] = 1.0

cost = common.generate_cost (domain, resistance, start, destination)

plt.imshow (cost)
plt.colorbar ()
plt.show ()
