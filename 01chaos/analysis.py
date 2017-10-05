import numpy as np

data = np.loadtxt("data", delimiter=",")
min = data[0][0]
max = data[0][1]
num = int(data[1][0])
step = data[1][1]

points = data[2::]
xs = np.array([x[0] for x in points])
ys = np.array([y[1] for y in points])
xs = xs[::-1]                            #reverse
ys = ys[::-1]
lambda_list = np.unique(xs)[::-1]
lambda_N = len(lambda_list)              #the number of lambda
x_list = []

for i in range(lambda_N):
	x_list.append(ys[num*i:num*(i+1)])   
	x_list[i] = np.unique(x_list[i])

count = 2
for j in range(lambda_N):
	if len(x_list[j]) == count:
		print(lambda_list[j], count)
		count = 2*count
		if count > 200:
			print('Chaos!')
			break


	
				


