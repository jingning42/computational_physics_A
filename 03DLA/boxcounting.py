#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from shutil import copyfile
from math import log


def factors(n):
	return [i for i in range(1, n+1) if n % i == 0]




data = np.loadtxt("data", delimiter=",", dtype=int)
n_item = data.shape[0]
xx = data[:, 0]
yy = data[:, 1]
center = xx[0]  # xx[0] == yy[0]
xx -= min(xx)
yy -= min(yy)

xxx = []
yyy = []
NN = []
radius = int(min(max(xx), max(yy))/72)*72
epsilons_recip = factors(radius)
for i in range(n_item):
	if xx[i]<radius and yy[i]<radius:
		xxx.append(xx[i])
		yyy.append(yy[i])
#print(epsilons_recip)



bitmap = np.zeros((radius, radius), dtype=np.int)
bitmap[xxx, yyy] = 1
for k in epsilons_recip:
	count = 0
	length = int(radius/k)
#	print('length', length)
	for i in range(k):
		left = i*length
		right = (i+1)*length
		for j in range(k):
			up = j*length
			down = (j+1)*length
			patch = bitmap[up:down, left:right]
			if np.count_nonzero(patch) != 0:
				count += 1
#	print('count', count)
	NN.append(count)



logepsilons_recip = [log(i) for i in epsilons_recip]
logNN = [log(i) for i in NN]
A = np.vstack([logepsilons_recip, np.ones(len(logepsilons_recip))]).T
m, c = np.linalg.lstsq(A, logNN)[0]


#print ('radius:', radius)
#print ('interval:', interval)
#print ('sum: ', NN[-1])
#print(m,c)

line = 'y=' + str(format(m, '0.3f')) + '*x' + '+' +  str(format(c, '0.3f'))
plt.plot(logepsilons_recip, logNN, 'o', label='Original data', markersize=5)
plt.plot(logepsilons_recip, [m*i+c for i in logepsilons_recip], 'r', label='Fitted line '+line)
plt.legend(loc='upper left')
#plt.scatter(logrr, logNN)

plt.xlabel('ln(r)')
plt.ylabel('ln(N)')
plt.suptitle('Box-counting method for ' + str(n_item) + ' particles, the fractal dimension is ' + str(format(m,'0.3f')))

#plt.show()

DST_DIR = 'results'
filename = str(n_item) + 'boxcounting'
#copyfile('data', DST_DIR + '/' + filename + '.txt')
plt.savefig(DST_DIR + '/' + filename + '.png')
plt.savefig(DST_DIR + '/' + filename + '.pdf')

