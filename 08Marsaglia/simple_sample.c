#include<stdio.h>
#include<math.h>

#define N 10000   // the amount of random numbers
#define PI 3.141592653589793

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


int main() {

	double RN[2*N], cost[N], sint[N], phi[N], x[N], y[N], z[N];
	RNG16807(RN, 2*N);  //call the function

	for (int i=0; i<N; i++) {
		cost[i] = 1-2*RN[2*i];        // cost = cos(theta)
		sint[i] = sqrt(1-cost[i]*cost[i]);  // sint = sin(theta)
		phi[i] = 2*PI*RN[2*i+1];

		x[i] = sint[i]*cos(phi[i]);
		y[i] = sint[i]*sin(phi[i]);
		z[i] = cost[i];
		printf("%lf,%lf,%lf\n", x[i], y[i], z[i]);
	}
	return 0;
}
