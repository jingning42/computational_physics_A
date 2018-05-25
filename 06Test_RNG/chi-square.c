/* Testing Random-Number Generators*/

#include<stdio.h>
#define N 30000000   // totally N random numbers
#define K 30     // Number of cells

double RN[N];     // random numbers

int main() {
	/* m = aq+r, q = [m/a], r = m mod a */
//    int a = 16807, m = 2147483647, q = 127773, r = 2836; // 16807
    int a = 329, m = 100000001, q = 303951, r = 122; // randomz

	int z = 1;   // seed
	double temp;

	/* Random-Number Generators: schrage method */
	for (int i=0; i<N; i++) {
		temp = a*(z%q) - r*(int)(z/q);
		if (temp>=0)
			z = temp;
		else
			z = temp + m;
		RN[i] = (double) z/m;
	}


	/* Chi-Square Test */
	int o[K] = {};    // observed frequency for ith cell
	double ei = N/K;  // Expected frequency
	double D = 0;     // chi-square distribution 
	double Di;
	for (int j=0; j<N; j++) {
		int i = (RN[j]/(1.0/K));
		o[i] += 1;
	}

	printf("%10s%15s%15s%10s\n", "Cell", "Observed", "Expected", "Di");
	for (int i=0; i<K; i++) {
		Di = ((o[i]-ei)*(o[i]-ei)/ei);
		printf("%10d%15d%15.1lf%10.3lf\n", i, o[i], ei, Di);
		D += Di;
	}

	printf("D = %lf\n", D);
	return 0;
}
