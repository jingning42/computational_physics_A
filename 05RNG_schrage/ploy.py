#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from shutil import copyfile

filename = 10000
range = 1
plt.axis([0, range, 0, range])   # Range = 1
plt.grid()

data = np.loadtxt("data", delimiter=",")
yy = data[::2]
xx = data[1::][::2]
s = plt.scatter(xx, yy)

plt.xlabel('x')
plt.ylabel('y')
plt.suptitle('%d Points!'%(filename/2))

#plt.show()
plt.savefig('result/%d.png'%filename)
copyfile('data', 'result/%d.txt'%filename)
