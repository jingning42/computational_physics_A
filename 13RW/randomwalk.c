/*  Monte Carlo Simulation of particles' random walk
    in the external force field (F~sinwt) */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100      // numbers of particles
#define F 0.1	    // frequency of force field
#define A 1.0     	// A is alpha
#define T 100       // Maximun time is t = T


int RW(int x, int t) {
	double y = (double) rand()/RAND_MAX;
	if (y < 0.5*(1+A*sin(F*t))) {
		return x+1;
	}
	else
		return x-1;
}

int main() {
	int x[N]={};  // x[i] is displacement of ith particle at t moment
	printf("%d, %lf, %lf, %d", N, F, A, T);
	for (int i=0; i<N-1; i++) printf(", %d", 0);
	printf("\n");
	for (int t=0; t<T; t++) {
		double ax=0, ax2=0, varx;  // average x, average of x square, variance
		printf("%d", t);
		
		for (int i=0; i<N; i++) {
			printf(", %d", x[i]);
			ax += x[i];
			ax2 += x[i]*x[i];
			x[i] = RW(x[i], t);
		}

		ax = ax/N;
		ax2 = ax2/N;
		varx = ax2 - ax*ax;
		printf(", %lf, %lf\n", ax, ax2);
//		printf(", %lf, %lf, %lf\n", ax, ax2, varx);
	}
	return 0;
}

