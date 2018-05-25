/* Testing Random-Number Generators*/

#include <stdio.h>
#include <math.h>
#define N 100000000   // totally N random numbers

double RN[N];     // random numbers

int main() {
	/* m = aq+r, q = [m/a], r = m mod a */
//	int a = 16807, m = 2147483647, q = 127773, r = 2836; // 16807
	int a = 329, m = 100000001, q = 303951, r = 122;  // randomz
	
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


	/* linear correlation coefficient test, l=1-10 */
	for (int l=0; l<1000; l++) {
		double Sum=0, Related_Sum=0, Square_Sum=0, Mean, RMS, Related_Mean;
		double Cor_Coef;
		for (int i=0; i<N; i++) {
			Sum += RN[i];
			Square_Sum += RN[i]*RN[i];
		}
		for (int i=0; i<N-l; i++) {
			Related_Sum += RN[i]*RN[i+l];
		}
		Mean = Sum/N;
		RMS = Square_Sum/N;
		Related_Mean = Related_Sum/N;
		Cor_Coef = (Related_Mean-Mean*Mean)/(RMS-Mean*Mean);
		printf("%d, %lf\n", l, Cor_Coef);
	}
	return 0;
}
