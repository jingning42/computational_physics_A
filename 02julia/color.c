#include <stdio.h>
#include <math.h>

#define XY_RANGE 2
#define STEP 0.001
#define RADIUS 200
#define MAX_NUM 100
#define ZERO 0.00000001

int is_julia(double x_0, double y_0, double a, double b, int MIN_NUM) {
	double x = x_0, y = y_0;
	double z2;

	for (int i = 0; i < MAX_NUM; i++) {
		double x_next, y_next;
		x_next = (x*x - y*y) + a;
		y_next = 2*x*y + b;
		x = x_next;
		y = y_next;
		z2 = x*x + y*y;
/*		printf("x = %lf, y = %lf, z = %lf\n", x, y, z2);   for test */
		if (z2 > RADIUS) {
			if (i < MIN_NUM) {
				return 0;
			}
			else {
				printf("%d, %f, %f, %f, %f\n", i, x_0, y_0, x, y);
				return 1;
			}
		}
		if (z2 < ZERO) {
			return 0;
		}
	}
	printf("%d, %f, %f, %f, %f\n", 10000, x_0, y_0, x, y);
	return 1;
}


int main() {
	
	double a, b; 
	int	count = 0;
	int MIN_NUM;

	fprintf(stderr, "This program calculates the Julia Set of C = a + i b.\n");
	fprintf(stderr, "Input a: ");
	scanf("%lf", &a);
	fprintf(stderr, "Input b: ");
	scanf("%lf", &b);
	fprintf(stderr, "Input the min number of iteration: ");
	scanf("%d", &MIN_NUM);
	printf("%f, %f, %d, %d, %d\n", a, b, MIN_NUM, 0, 0);

	for (double x_0 = 0-XY_RANGE; x_0 < XY_RANGE; x_0 = x_0 + STEP) {
		for (double y_0 = 0-XY_RANGE; y_0 < XY_RANGE; y_0 = y_0 + STEP) {
			if(is_julia(x_0, y_0, a, b, MIN_NUM)) {
				count++;
			}
		}
	}
	fprintf(stderr, "Totally %d points!\n", count);
	return 0;
}
