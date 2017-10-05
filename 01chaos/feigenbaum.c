#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define ITERATION_NUM 100000 /*define the number of iteration for each lambda*/

int main() {
	double x=0.15;    	/*initial value of x*/
	int count = 0;    	/*to count the number of data point*/
	double Min, Max;    /*the range of lambda is [min, max]*/
	int Num;            /*the number of x to print out for each lambda*/
	double Step;        /*the step of lambda*/

	/*some information about the input*/
	fprintf(stderr, "Please input some parameters.\nThe number of data points N = (Max-Min)*Num*Step \n");
	fprintf(stderr, "Min(the min of lambda): ");
	scanf("%lf", &Min);
	fprintf(stderr, "Max(the max of lambda): ");
	scanf("%lf", &Max);
	fprintf(stderr, "Num(the number of x to print out for each lambda): ");
    scanf("%d", &Num);
	fprintf(stderr, "Step(the step of lambda): ");
	scanf("%lf", &Step);
    printf("%f, %f\n %d, %f\n", Min, Max, Num, Step); 


	for (double lambda = Max; lambda > Min; lambda = lambda-Step) {
		for (int i=0; i<ITERATION_NUM; i++) {
			x = lambda*sin(PI*x);   		  /*iteration equation*/
			if (i>(ITERATION_NUM-Num-1)) {
				printf("%lf, %lf\n", lambda, x);          
 	            /*print out the last some iterative values of x */
				count++;
			}
		}
	}
	fprintf(stderr, "Totally %d points!\n", count);
	/*print out the number of all data points.*/
	return 0;
}
