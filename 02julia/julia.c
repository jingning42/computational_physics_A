#include <stdio.h>
#include <math.h>

#define RADIUS 200               // radius for judgment condition
#define MAX 2                    // plot range [-2,2]*[-2,2]
#define STEP 0.001               // step for x and  y
#define ZERO 0.00000001          // define zero as a small number


/*this function return 1 if the point is belong to julia set, else return 0*/
int is_julia(double x_0, double y_0, double a, double b, int Num) {
	double x = x_0, y = y_0;
	double z2;						         // z2 means square of z

	for (int i = 0; i < Num; i++) {   
		double x_next, y_next;
		x_next = (x*x - y*y) + a;            // iteration equation
		y_next = 2*x*y + b;
		x = x_next;
		y = y_next;
		z2 = x*x + y*y;     
		if (z2 > RADIUS || z2 < ZERO) {      
		// condition for points not in julia set
			return 0;     
		}
	}
	return 1;
}


int main() {
	
	double a, b; 
	int Num;
	int count = 0;        //count the number of points in julia set

	fprintf(stderr, "This program calculates the Julia Set of C = a + i b.\n");
	fprintf(stderr, "Input a between [-1,1]: ");
	scanf("%lf", &a);
	fprintf(stderr, "Input b between [-1,1]: ");
	scanf("%lf", &b);
	fprintf(stderr, "Input number of iteration for each points: ");
	scanf("%d", &Num);
	printf("%f, %f\n", a, b);
	printf("%d, %d\n", Num, 0);

	for (double x_0 = 0-MAX; x_0 < MAX; x_0 = x_0 + STEP) {
		for (double y_0 = 0-MAX; y_0 < MAX; y_0 = y_0 + STEP) {
			if (is_julia(x_0, y_0, a, b, Num)) { 
				printf("%f, %f\n", x_0, y_0);
				count ++;
			}
		}
	}
	fprintf(stderr, "Totally %d Points!\n", count);
	return 0;
}
