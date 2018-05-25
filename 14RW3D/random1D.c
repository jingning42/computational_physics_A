/*  Monte Carlo Simulation of 1D simple symmetric random walk */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 10000     // numbers of particles
#define N 200    // Maximun walking steps


// random walk function
int RW(int x) {
	int m = rand();
	if (m%2 == 0) {
		return x-1;
	}
	else
		return x+1;
}

int main() {
	int x[M]={};  // x[i] is displacement of ith particle at t moment
	double Pd;    // probability of returning origin point

	printf("%d, %d, 1\n", M, N);
	for (int t=1; t<N+1; t++) {
		int count = 0; // count the number of particles return origin	

		for (int i=0; i<M; i++) {
			x[i] = RW(x[i]);
			if (x[i] == 0){
				count ++;
			}
		}
		Pd = (double) count/M; 
		printf("%d, %d, %0.15lf\n", t, count, Pd);

	}
	return 0;
}
