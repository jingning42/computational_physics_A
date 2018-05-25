/*  Monte Carlo Simulation of 3D simple symmetric random walk */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 1000000     // numbers of particles
#define N 1000    // Maximun walking steps

/* random walk implement */
int RW(int x[3]) {
	int m = rand();
	switch (m%6) {
		case 0: x[0] -= 1; break;
		case 1: x[0] += 1; break;
		case 2: x[1] -= 1; break;
		case 3: x[1] += 1; break;
		case 4: x[2] -= 1; break;
		case 5: x[2] += 1; break;
		default: printf("error!\n");
	}
	return 0;
}

int x[M][3]={};  // x[i] is displacement of ith particle at t moment
int main() {
	double Pd;    // probability of returning origin point

	printf("%d, %d, 3\n", M, N);
	for (int t=1; t<N+1; t++) {
		int count = 0; // count the number of particles return to Origin	

		for (int i=0; i<M; i++) {
			RW(x[i]);
			if ((x[i][0]==0)&&(x[i][1]==0)&&(x[i][2]==0)){
				count ++;
			}
		}
		Pd = (double) count/M; 
		printf("%d, %d, %0.15lf\n", t, count, Pd);

	}
	return 0;
}
