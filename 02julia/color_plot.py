import matplotlib.pyplot as plt
import numpy as np
from shutil import copyfile

data = np.loadtxt("data", delimiter=",")
# C = a + i b
a = data[0][0]
b = data[0][1]
min_num = data[0][2]

points = data[1::]
ns = [i[0] for i in points]
xs = [i[1] for i in points]
ys = [i[2] for i in points]

#colors = ['b','g','r','c','m','y','k','w']
factor = 5
cs = [((int(n)-min_num+1)*factor)%100 for n in ns]


plt.scatter(xs, ys, c = cs, linewidths=0, s=10)
plt.xlabel('x')
plt.ylabel('y')
plt.suptitle('Julia Set of C = ' + str(a) + ' + i '+ str(b))
#plt.show()


DST_DIR = 'results'
filename = "a" + str(a) + "b" + str(b) + "num" + str(min_num)+ "factor" + str(factor)
file_dir = DST_DIR + '/' + filename

copyfile('data', file_dir + '.txt')
plt.savefig(file_dir + '.pdf')
plt.savefig(file_dir +'.png')


