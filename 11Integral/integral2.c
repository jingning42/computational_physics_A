#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int D = 5;    // dimension
	double x_max[] = {7/10.0, 4/5.0, 9/10.0, 1.0, 11/10.0};    
	// upper bound
	double x[D];   // a point's coordinates
	double integral, Tvalue = 2.55948000000000;   

	srand(100);
	printf("%15s,%20s,%20s\n", "N", "Integral", "Error");
	for (int j=1; j<10; j++) {
		int	K = pow(10, j);  // K is sampling number
		double sum = 0;      // sum of f(x_i)

		for (int i=0; i<K; i++) {
			double fun_value = 6;   // f(x)
			for (int l=0; l<D; l++) {
				x[l] = x_max[l]*rand()/RAND_MAX;
				fun_value -= x[l]*x[l];
			}
			sum += fun_value;
		}
		
		for (int l=0; l<D; l++) {
			sum *= x_max[l];
		}
		
		integral = sum/K;

		printf("%15d,%25.15lf,%25.15le\n", K, integral,	fabs(integral-Tvalue));
	}
	return 0;
}
