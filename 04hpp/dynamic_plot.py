#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from shutil import copyfile

plt.axis([0, 1000, 0, 1000])   # Range = 100
plt.ion()
plt.grid()
f = open('data', 'r')
for line in f:
	temp = np.fromstring(line, sep=',', dtype=int)[:-1]
	step = temp.reshape((-1, 3))
	yy = step[:, 0]
	xx = step[:, 1]
	value = step[:, 2]
	s = plt.scatter(xx, yy, s=1)
	plt.pause(0.0001)
	s.remove()

f.close()

plt.xlabel('x')
plt.ylabel('y')
plt.suptitle('HPP Model')

'''
#plt.show()
DST_DIR = 'results'
filename = str(n_item) + 'dynamic'
#copyfile('data', DST_DIR + '/' + filename + '.txt')
ani.save(DST_DIR + '/' + filename + ".gif", dpi=120, writer='imagemagick')
'''
