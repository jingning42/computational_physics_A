#include<stdio.h>

#define N 10000   // the amount of random number to generate

int main() {
	/* m = aq+r, q = [m/a], r = m mod a */
	int a = 16807, b = 0, m = 2147483647, q = 127773, r = 2836;
	int z = 1; // seed is 1
	int temp;
	
	printf("%.15lf", (double)z/m);

	for (int i=1; i<N; i++) {
		temp = a*(z%q) - r*(int)(z/q);
		if (temp>=0)
			z = temp;
		else
			z = temp + m;
		printf(", %.15lf",(double)z/m);
	}
	return 0;
}
