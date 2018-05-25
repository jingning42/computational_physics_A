/* Testing Random-Number Generators*/

#include <stdio.h>
#include <math.h>
#define N 10000000   // totally N random numbers

double RN[N];     // random numbers

int main() {
	/* m = aq+r, q = [m/a], r = m mod a */
//	int a = 16807, m = 2147483647, q = 127773, r = 2836; // 16807
	int a = 329, m = 100000001, q = 303951, r = 122; // randomz
	int z = 1;   // seed
	int temp;

	/* Random-Number Generators: schrage method */
	for (int i=0; i<N; i++) {
		temp = a*(z%q) - r*(int)(z/q);
		if (temp>=0)
			z = temp;
		else
			z = temp + m;
		RN[i] = (double) z/m;
	}


	/* kth-order moment test, k=1-5 */
	for (int j=3; j<=7; j++) {
		int	M = pow(10, j);
		printf("N = %d\n", M);
		printf("%5s%20s%20s%20s\n", "k", "kth moment", "exact value", "deviation");
		for (int k=1; k<=5; k++) {
			double k_order_sum = 0;
			double exact_value = 1.0/(1+k);
			for (int i=0; i<M; i++) {
				k_order_sum += pow(RN[i], k);
			}
			double k_moment = k_order_sum/M;
			double deviation = fabs(k_moment-exact_value);
			printf("%5d%20.15lf%20.15lf%20.15lf\n", k, k_moment, exact_value, deviation);
		}
	}
	return 0;
}
