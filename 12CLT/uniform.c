#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10        // sum of N items
#define M 100000    // sampling times


double x[N][M], sum[M], y[M];
int main() {
	double mean=0.5, standard_deviation=1/sqrt(12); 

	srand(42);
	for (int j=0; j<M; j++) {
		sum[j] = 0;
		for (int i=0; i<N; i++) {
			x[i][j] = 1.0*rand()/RAND_MAX;
			sum[j] += x[i][j];
		}
		y[j] = (sum[j]/N-mean)/(standard_deviation/sqrt(N));
		printf("%lf, ", y[j]);
	}

	printf("%d, %d\n", N, M);
	return 0;
} 
