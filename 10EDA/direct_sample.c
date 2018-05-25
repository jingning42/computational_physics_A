#include <stdio.h>
#include <stdlib.h>

#define K 111         // cell numbers
#define N 10000       // how many numbers to sampling

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

double RN[N];

int main() {
	
	int energy[K], counts[K], sum=0;
	double p[K], xi[K];   // xi[i] = p[1]+p[2]+...+p[i]

	/* read data file into array  */
	FILE *myFile;
	if ((myFile = fopen("data.txt", "r")) == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}

	for (int i=1; i<K; i++) {
		fscanf(myFile, "%d", &energy[i]);
		fscanf(myFile, "%d", &counts[i]);
		sum += counts[i];
	}

	/* calculate frequency from counts */
	xi[0] = 0;    // boundary condition 
	for (int i=1; i<K; i++) {
		p[i] = (double) counts[i]/sum;
		xi[i] = xi[i-1]+p[i];
	//	printf("%lf\n", xi[i]);  for test
	}
	
	RNG16807(RN, N);  // generate N random numbers
	for (int i=0; i<N; i++) {
		for (int j=0; j<K; j++) {
			if (RN[i]<xi[j]) {
				printf("%d, ", energy[j]);
				break;  // sampling number is energy[j]
			}
		}
	}
	printf("%d\n", N);
	return 0;
}
