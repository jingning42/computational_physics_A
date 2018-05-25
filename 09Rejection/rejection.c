#include<stdio.h>
#include<math.h>

#define N 100000   // the amount of random numbers
#define PI 3.141592653589793
#define E 2.71828182845905

/* using 16807 random number generator */

int RNG16807(double random[], int M) {
	/* m = aq+r, q = [m/a], r = m mod a    */
	int a = 16807, m = 2147483647, q = 127773, r = 2836;
	int z = 1; // seed = 1
	int temp;

	for (int i=0; i<M; i++) {
		temp = a*(z%q) - r*(int)(z/q);
		if (temp>=0)
			z = temp;
		else
			z = temp + m;
		random[i] = (double) z/m;
	}
	return 0;
}


double RN[2*N], xi_1[N], xi_2[N], x[N], y[N], p[N];

int main() {

	int count = 0;
	RNG16807(RN, 2*N);  // generate 2N random numbers

	for (int i=0; i<N; i++) {
		xi_1[i] = RN[2*i];
		xi_2[i] = RN[2*i+1];  

		x[i] = tan(PI*(xi_1[i]-0.5));
		y[i] = xi_2[i]*1.6/(PI*(1+x[i]*x[i]));
		
		if (y[i]<pow(E,-x[i]*x[i]/2)/sqrt(2*PI)) {
			printf("%.2lf, ", x[i]);     // print accepted x[i]
			count += 1;
		}
	}
	printf("%d, %d", N, count);
	return 0;
}
