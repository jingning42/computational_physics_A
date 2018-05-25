#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from shutil import copyfile
from math import log




data = np.loadtxt("data", delimiter=",", dtype=int)
n_item = data.shape[0]
xx = data[:, 0]
yy = data[:, 1]
center = xx[0]  # xx[0] == yy[0]
xx -= center
yy -= center




radius = min(map(abs, [max(xx), min(xx), max(yy), min(yy)]))
interval = int(radius/30)
rr = range(radius)[::interval]
NN = [0]

for i in range(len(rr)-1):
	count = 0
	for j in range(n_item):
		if max(abs(xx[j]), abs(yy[j])) < rr[i+1]:
			count += 1
#	print (count)
	NN.append(count)

logrr = [log(i) for i in rr[1:]]
logNN = [log(i) for i in NN[1:]]
A = np.vstack([logrr, np.ones(len(logrr))]).T
m, c = np.linalg.lstsq(A, logNN)[0]

#print ('radius:', radius)
#print ('interval:', interval)
#print ('sum: ', NN[-1])
#print(m,c)




line = 'y=' + str(format(m, '0.3f')) + '*x' + '+' +  str(format(c, '0.3f'))
plt.plot(logrr, logNN, 'o', label='Original data', markersize=5)
plt.plot(logrr, [m*i+c for i in logrr], 'r', label='Fitted line '+line)
plt.legend(loc='upper left')
#plt.scatter(logrr, logNN)

plt.xlabel('ln(r)')
plt.ylabel('ln(N)')
plt.suptitle('Sandbox method for ' + str(n_item) + ' particles, the fractal dimension is ' + str(format(m,'0.3f')))

#plt.show()

DST_DIR = 'results'
filename = str(n_item) + 'sandbox'
#copyfile('data', DST_DIR + '/' + filename + '.txt')
plt.savefig(DST_DIR + '/' + filename + '.png')
plt.savefig(DST_DIR + '/' + filename + '.pdf')

