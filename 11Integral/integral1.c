#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000000


int main() {
	
	double a = 0, b = 1;
	double integral, Tvalue = 1.04530130813919;
	
	srand(10);
	printf("%15s,%20s,%20s\n","N", "Integral", "Error");
	for (int j=1; j<10; j++) {
		int	K = pow(10, j);   // K is sampling number
		double sum = 0;       // sum of f(x_i)
		for (int i=0; i<K; i++) {
			double x = 1.0*rand()/RAND_MAX;
			sum += sqrt(x + sqrt(x));
		}
		integral = (b-a)*sum/K;
		printf("%15d,%25.8lf,%25.8le\n", K, integral, fabs(integral-Tvalue));
	}
	return 0;
}
