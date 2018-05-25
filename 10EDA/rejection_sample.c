#include <stdio.h>
#include <stdlib.h>

#define K 111         // cell numbers
#define N 10000       // how many numbers to sampling

/* using 16807 random number generator */
double Fun1(double x);
double Fun2(double y);
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

double RN[2*N], xi_1[N], xi_2[N], x[N], y[N];

int main() {
	
	int energy[K], counts[K], sum=0, new_count=0;
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
	}
	

	RNG16807(RN, 2*N);  // generate 2N random numbers
	for (int i=0; i<N; i++) {
		xi_1[i] = RN[2*i];
		xi_2[i] = RN[2*i+1];
		x[i] = Fun1(xi_1[i]);
		y[i] = xi_2[i]*Fun2(x[i]);   //Fun2 = F(x)
		if (  y[i]<p[(int)(x[i]-2900+1)]  ) {
			printf("%d, ",(int)x[i]);  // accepted!
			new_count += 1;
		}
	}
	printf("%d, %d\n", N, new_count);
	return 0;
}

/* Fun1 is F^-1(x) */
double Fun1(double xx) {
	double m1=0.409512, m2=0.983272, a1=0.00431066, b1=0.063751, c1=0.0027885;
	double yy;
	if (xx<m1) {
		yy = xx/a1+2900;
	}
	else if (xx<m2) {
		yy = (xx-m1)/b1+2995;
	}
	else {
		yy = (xx-m2)/c1+3004;
	}
	return yy;
}
/* Fun2 is F(x) */
double Fun2(double xx) {
	double a=0.00726337, b=0.10741919, c=0.00469857, yy;
	if (xx<2995) 
		yy=a;
	else if (xx<3004) 
		yy=b;
	else 
		yy=c;
	return yy;
}
