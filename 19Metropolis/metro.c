#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500000  // all step
#define M 50000   

int main() {
	double x0, y0, x1, y1, E0, E1, dE, r, w;
	double sumx=0, sumy=0, sumxy=0;  
	double ax2, ay2, axy2;   // average of x^2, y^2, x^2+y^2
	int step;
	x0 = 10.0, y0 = 10.0;

	for (int i=0; i<N; i++) {
		x1 = x0 + 0.2*rand()/RAND_MAX-0.1;    // change status
		y1 = y0 + 0.2*rand()/RAND_MAX-0.1;
		E0 = (x0*x0 + y0*y0)/2;     // energy
		E1 = (x1*x1 + y1*y1)/2;
		dE = E1 - E0;
		if (i>M) {
			sumx += x1*x1;
			sumy += y1*y1;
			sumxy += x1*x1 + y1*y1;
		}	
		if (dE <= 0) {
			x0 = x1;
			y0 = y1;
			printf("%lf, %lf\n", x1, y1);
		}
		else {
			r = 1.0*rand()/RAND_MAX;
			w = pow(M_E, -dE);
			if (r < w) {
				x0 = x1;
				y0 = y1;
				printf("%lf, %lf\n", x1, y1);
			}
		}
	}
	ax2 = sumx/(N-M);
	ay2 = sumy/(N-M);
	axy2 = sumxy/(N-M);
	fprintf(stderr, "<x^2> = %lf,\n<y^2> = %lf,\n<x^2+y^2> = %lf\n", ax2, ay2, axy2);
	return 0;
}
