import matplotlib.pyplot as plt
import numpy as np
from shutil import copyfile

data = np.loadtxt("data", delimiter=",")
num = data.shape[0]

xs = data[:, 0]
ys = data[:, 1]

plt.scatter(xs, ys, s=0.5)
plt.xlabel('x')
plt.ylabel('y')
plt.suptitle(str(int(num)) + ' particles!')
#plt.show()


DST_DIR = 'results'
filename = str(int(num))
copyfile('data', DST_DIR + '/' + filename + '.txt')
plt.savefig(DST_DIR + '/' + filename + ".pdf")
plt.savefig(DST_DIR + '/' + filename + ".png")


