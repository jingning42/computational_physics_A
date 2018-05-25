#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3       // sum of N items
#define M 100000   // sampling number in one simulation

/* Rejection Sampling Method */

// x1: sampling values 
// sum: sum of N items
// y: normalized sum of N items

int main() {
	int count = 0;    // counter number
	double x1, x2, sum, y;     
	double mean = 1.0/6, standard_deviation = 1; 

	srand(12);  // seed = 12
	for (int j=0; j<M; j++) {
		sum = 0.0;
		int i = 0;
		while (i<N) {
			x1 = 4.0*rand()/RAND_MAX - 2.0;
			x2 = 0.5*rand()/RAND_MAX;
			if ((x1<=0 && x2<=0.25*x1+0.5)||(x1>0 && x2<=0.25)){
				sum += x1;
				i++;
				count ++;
			}
		}
		y = (sum/N-mean)/(standard_deviation/sqrt(N));
		printf("%lf, ", y);   // print out 
	}

	printf("%d, %d\n", N, M);
	return 0;
} 
