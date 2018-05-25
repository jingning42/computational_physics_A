#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from shutil import copyfile

filename = 'circle'
plt.axis([0, 1000, 0, 1000])   # Range = 1000
plt.grid()
f = open('data', 'r')
data = f.readlines()
f.close()
count = 0
s = plt.scatter([], [], s=1)
for line in data[:1100][::100]:
	temp = np.fromstring(line, sep=',', dtype=int)[:-1]
	step = temp.reshape((-1, 3))
	yy = step[:, 0]
	xx = step[:, 1]
	s.remove()
	s = plt.scatter(xx, yy, s=1)

	plt.xlabel('x')
	plt.ylabel('y')
	plt.suptitle('HPP Model: '+filename+str(100*count)+' step')
	plt.savefig('result/'+filename+str(100*count)+'step')	
	count += 1

'''
#plt.show()
DST_DIR = 'results'
filename = str(n_item) + 'dynamic'
#copyfile('data', DST_DIR + '/' + filename + '.txt')
'''
