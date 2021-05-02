#!/usr/bin/python3

import numpy as np
import common
from matplotlib import pyplot as plt

domain      = np.zeros ((10, 10))
start       = (1, 1)
destination = (8, 8)

domain[2, 4] = -1.0

domain[1, 3] = -1.0
domain[2, 3] = -1.0
domain[3, 3] = -1.0
domain[3, 2] = -1.0
domain[3, 1] = -1.0

domain[6, 3] = 20.0

cost = common.generate_cost (domain, start, destination)

plt.imshow (cost)
plt.colorbar ()
plt.show ()
