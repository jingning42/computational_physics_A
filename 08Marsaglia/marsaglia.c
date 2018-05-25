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

	double RN[2*N], u[N], v[N], r2[N], x[N], y[N], z[N];
	RNG16807(RN, 2*N);  //call the function

	for (int i=0; i<N; i++) {
		u[i] = RN[2*i]*2-1;       // u [-1,1] uniform distribution
		v[i] = RN[2*i+1]*2-1;     // v [-1,1]
		r2[i] = u[i]*u[i] + v[i]*v[i];   // r2 = r^2
		
		x[i] = 2*u[i]*sqrt(1-r2[i]);
		y[i] = 2*v[i]*sqrt(1-r2[i]);
		z[i] = 1 - 2*r2[i];
		printf("%lf,%lf,%lf\n", x[i], y[i], z[i]);
	}
	return 0;
}
