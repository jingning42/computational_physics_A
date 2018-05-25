#include <stdio.h>
#include <stdlib.h>


#define N 10000   // number of molecules
#define M 100000  // number of iterations

int main() {
	double ve[N];   // velocity of N particles
	
	// uniform distribution of velocity at begining
	for (int i=0; i<N; i++) {
		ve[i] = 2.0*rand()/RAND_MAX - 1;
	}

	double E_k=0, deltaE, demonE=0.0, T, delta=0.5;
	printf("%d, %d, %lf\n", N, M, delta);
	
	int r;          // a random number between 0 to N-1
	int accept=0;     // accept times
	double v0, v1;

	// calculate the kinetic energy of system
	for (int i=0; i<N; i++) {
		E_k += 0.5*ve[i]*ve[i];
	}

	// M iterations
	for (int k=0; k<M; k++) {

		r = rand()%N;  // choose a particle i at random among N particles
		v0 = ve[r];
		v1 = (2.0*rand()/RAND_MAX-1)*delta + ve[r];
		deltaE = 0.5*(v1*v1-v0*v0);


		if (deltaE <= 0 || demonE >= deltaE) {
			accept ++;
			ve[r] = v1;
			demonE = demonE - deltaE;
			E_k += deltaE;
			T = 2*E_k/N;
			printf("%d, %lf, %lf\n", accept, T, demonE);
		} // else rejected
	}

	// calculate average and variance of velocity
	double sum1=0, sum2=0, av, var;
	for (int i=0; i<N; i++) {
		sum1 += ve[i];
	}
	av = sum1/N;
	for (int i=0; i<N; i++) {
		sum2 += (ve[i]-av)*(ve[i]-av);
	}
	var = sum2/N;
	// print to screen
	fprintf(stderr, "N %d, M %d, delta %lf\n", N, M, delta);
	fprintf(stderr, "accept %d, rate %lf\n", accept, 1.0*accept/M);
	fprintf(stderr, "av %lf, var %lf\n", av, var);

	// print velocity to file
//	printf("%lf\n%lf\n%d\n%d\n%lf\n%lf\n", av, var, N, M, delta, 1.0*accept/M);
//	for (int i=0; i<N; i++) {
//		printf("%lf\n", ve[i]);
//	}
	return 0;
}


