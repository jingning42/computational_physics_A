#include<stdio.h>
#include<stdlib.h>

#define N 1000
#define M 1000
#define STEP 2000

int hpp_step(char s[2][M+1][N+1]);
int square(char s[2][M+1][N+1]);
int circle(char s[2][M+1][N+1]);
int hexagon(char s[2][M+1][N+1]);
double distance(int i, int j, int x, int y) {
	return (i-x)*(i-x) + (j-y)*(j-y);
	
}
double inner_product(int i, int j, int x, int y, double e1, double e2) {
	return (i-x)*e1 + (j-y)*e2;
}

int main() {
	/* s[2][N][M] show the grid states of gas,
	   s[0][N][M] is the former (t) states,
	   s[1][N][M] is the latter (t+1) states. 
	   the value of element is between 0 to 15. */
	char s[2][M+1][N+1] = {};          
	srand(1);

	
	/* set up the initial grid states by calling one of these functions */
//	square(s);
	circle(s);
//	hexagon(s);


	/* set up how many step this system last. */
	for (int step=0; step<STEP; step++) {
		hpp_step(s);
	}

	return 0;
}


/* gas particles of hpp model take one step when we call this function once */
int hpp_step(char s[2][N+1][M+1]) {
	
	char a;    // for temporary value

	/* the two for-loop below is dealing with the edge grid */
	for (int j=1; j<N; j++) {
	    a = s[0][1][j];
		s[0][0][j] = (a&5) + ((a&2)<<2) + ((a&8)>>2);
		a = s[0][N-1][j];
		s[0][N][j] = (a&5) + ((a&2)<<2) + ((a&8)>>2);
	}
	for (int i=1; i<M; i++) {
		a = s[0][i][1];
		s[0][i][0] = (a&10) + ((a&1)<<2) + ((a&4)>>2);
		a = s[0][i][N-1];
		s[0][i][N] = (a&10) + ((a&1)<<2) + ((a&4)>>2);
	}

	/* the main part,
	   every grid state at t+1 moment is decided by adjacent grid states at t. */
	for (int i=1; i<M; i++) {
		for (int j=1; j<N; j++) {
			char a = s[0][i-1][j];		// the up grid (i-1, j)
			char b = s[0][i][j-1];		// the left (i, j-1)
			char c = s[0][i+1][j];		// the down (i+1, j)
			char d = s[0][i][j+1];		// the right (i, j+1)
			char s_value = 0;
			if ( (a==5) || ((a>>3)&&(a!=10)) ) 
				s_value += 8;
			if ( (b==10) || (((b>>2)&1)&&(b!=5)) )
				s_value += 4;
			if ( (c==5) || (((c>>1)&1)&&(c!=10)) )
				s_value += 2;
			if ( (d==10) || ((d&1)&&(d!=5)) )
				s_value += 1;
			s[1][i][j] = s_value;		// update the (i,j) grid state
		}
	}

	/* below we update the state of s[0][i][j] by s[1][i][j] */
	for (int i=1; i<M; i++) {
		for (int j=1; j<N; j++) {
			if (s[1][i][j] > 0) 
				printf("%d, %d, %hhd, ", i, j, s[1][i][j]);		
				// print out coordinate and state of grid
			s[0][i][j] = s[1][i][j];		// update
		}
	}	
	printf("\n");
	return 0;
}

/* square(), circle(), hexagon() are three function 
   to dealing with different initial area conditions, 
   with 10000 particles in different center boxs,
   all the center boxes have the same area */
int square(char s[2][M+1][N+1]) {
	char ini_state[4] = {8, 4, 2, 1};
	/* square box: 100*100 */
	for (int i=M/2-50; i<M/2+50; i++) {
		for (int j=N/2-50; j<N/2+50; j++) {
			s[0][i][j] = ini_state[rand()%4];
		}
	}
	return 0;
}

int circle(char s[2][M+1][N+1]) {
	/* circle box: Pi*R*R=10000, Radius=56.41895835 */
	char ini_state[4] = {8, 4, 2, 1};
	double R = 56.41895835;
	for (int i=1; i<M; i++) {
		for (int j=1; j<N; j++) {
			if (distance(i,j,M/2,N/2) < R*R) 
				s[0][i][j] = ini_state[rand()%4];
		}
	}
	return 0;	
}

int hexagon(char s[2][M+1][N+1]) {
	/* hexagon box: 1.5*(3)^(1/2)*l*l=10000, l-length 
	   some tricky ways are need with hexagon box*/
	char ini_state[4] = {8, 4, 2, 1};
	double l = 62.04032394;
	double dis = 53.72849659;
	double temp = 0.8660254;
	for (int i=447; i<554; i++) {
		for (int j=437; j<563; j++) {
			if (((i<M/2)&&(j<N/2)&&(inner_product(i,j,M/2,N/2,-0.5,-temp)<dis))
			 || ((i<M/2)&&(j>=N/2)&&(inner_product(i,j,M/2,N/2,-0.5,temp)<dis))
			 || ((i>=M/2)&&(j<N/2)&&(inner_product(i,j,M/2,N/2,0.5,-temp)<dis))
			 || ((i>=M/2)&&(j>=N/2)&&(inner_product(i,j,M/2,N/2,0.5,temp)<dis)))
			{
				s[0][i][j] = ini_state[rand()%4];
			}
		}
	}
	return 0;
}
