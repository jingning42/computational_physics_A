import matplotlib.pyplot as plt
import numpy as np
from shutil import copyfile

data = np.loadtxt("data", delimiter=",")
# C = a + i b
a = data[0][0]
b = data[0][1]
num = data[1][0]
points = data[2::]

xs = [x[0] for x in points]
ys = [y[1] for y in points]

plt.scatter(xs, ys, s=0.5)
plt.xlabel('x')
plt.ylabel('y')
plt.suptitle('Julia Set of C = ' + str(a) + ' + i '+ str(b) + ', N = ' +
str(int(num)))
#plt.show()

DST_DIR = 'results'
filename = "a" + str(a) + "b" + str(b) + "n" + str(int(num)) + "black"
copyfile('data', DST_DIR + '/' + filename + '.txt')
plt.savefig(DST_DIR + '/' + filename + ".pdf")
plt.savefig(DST_DIR + '/' + filename + ".png")


