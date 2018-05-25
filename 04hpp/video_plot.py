#!/usr/bin/env python3

import numpy as np
from shutil import copyfile 

import matplotlib 
matplotlib.use("Agg")

import matplotlib.pyplot as plt
import matplotlib.animation as animation


filename = "circle500"
fig = plt.figure()
plt.axis([0, 1000, 0, 1000])   # Range = 1000
#plt.grid()
plt.xlabel('x')
plt.ylabel('y')

scatter = plt.scatter([], [], s=1)

def update(wrap, *args):
    count, line = wrap
    print("Frame #%d" % count)
    temp = np.fromstring(line, sep=',', dtype=int)[:-1]
    step = temp.reshape((-1, 3))
    scatter.set_offsets(step[:, 0:2])
    plt.suptitle('HPP Model: %s %d step(s)'%(filename, count))
    return scatter,

f = open('data', 'r')
ani = animation.FuncAnimation(
        fig, update, enumerate(f), interval=10, blit=True,
        save_count=100000)
ani.save("result/%s.mp4"%(filename), writer="ffmpeg")
copyfile('data', 'result/%s.txt'%(filename))
f.close()

