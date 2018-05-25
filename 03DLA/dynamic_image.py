#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from shutil import copyfile

N_FRAMES = 50
INTERVAL = 200

data = np.loadtxt("data", delimiter=",", dtype=int)
n_item = data.shape[0]

xx = data[:, 0]
yy = data[:, 1]

x_boundary = int((np.max(xx)-np.min(xx))/3)
y_boundary = int((np.max(yy)-np.min(yy))/3)

xx -= np.min(xx) - x_boundary
yy -= np.min(yy) - y_boundary

im_height = np.max(yy) + y_boundary
im_width = np.max(xx) + x_boundary

def update(i):
    print("Frame %d/%d" % (i, N_FRAMES))
    lo = int(i / N_FRAMES * n_item)
    hi = int((1 + i) / N_FRAMES * n_item)
    img[yy[lo:hi], xx[lo:hi]] = 0.0
    plot.set_array(img)
    return plot,

fig = plt.figure()
img = np.full((im_height, im_width), 1.0, dtype=np.float32)
plot = plt.imshow(img, animated=True, cmap="gray", vmin = 0.2, vmax= 1.0, interpolation="bilinear", origin="lower")
ani = FuncAnimation(
       fig, update,
       frames=np.arange(N_FRAMES),
       interval=INTERVAL, blit=True)

plt.xlabel('x')
plt.ylabel('y')
plt.suptitle('Totally ' + str(n_item) + ' particles!')

#plt.show()
DST_DIR = 'results'
filename = str(n_item) + 'ani'
copyfile('data', DST_DIR + '/' + filename + '.txt')
ani.save(DST_DIR + '/' + filename + ".gif", dpi=120, writer='imagemagick')
