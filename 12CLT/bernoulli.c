#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000000       // sum of N items
#define M 1000   // sampling number in one simulation


// x: sampling values 
// sum: sum of N items
// y: normalized sum of N items

int main() {
	double x, sum, y;     
	double mean=0.7, standard_deviation=sqrt(0.21); 

	srand(42);  // seed = 42
	for (int j=0; j<M; j++) {
		sum = 0.0;
		for (int i=0; i<N; i++) {
			double temp = 1.0*rand()/RAND_MAX;
			if (temp < 0.7) 
				x = 1.0;
			else
				x = 0.0;
			sum += x;
		}
		y = (sum/N-mean)/(standard_deviation/sqrt(N));
		printf("%lf, ", y);   // print out 
	}

	printf("%d, %d\n", N, M);
	return 0;
} 
