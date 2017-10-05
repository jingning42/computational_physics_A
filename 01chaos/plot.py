import matplotlib.pyplot as plt              #import some useful libraries
import numpy as np
from shutil import copyfile

data = np.loadtxt("data", delimiter=",")     #load data file from calculating
min = data[0][0]                        
max = data[0][1]
num = data[1][0]
step = data[1][1]

points = data[2::]
xs = [x[0] for x in points]
ys = [y[1] for y in points]

plt.scatter(xs, ys, s=0.5)                   #plot all data points
plt.xlabel('$\lambda$')
plt.ylabel('x')
plt.suptitle('$\lambda\in[%.2f,%.2f],  Num=%d,  Step=%.3f $'%(min, max, num, step))
#some parameters

DST_DIR = 'results'                          #result file directory
filename = "min" + str(min) + "max" + str(max) + "num" + str(num) + "step" + str(step)
copyfile('data', DST_DIR + '/' + filename + '.txt')   #copy data file
plt.savefig(DST_DIR + '/' + filename + ".pdf")        #save image
plt.savefig(DST_DIR + '/' + filename + ".png")

