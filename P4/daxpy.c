#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void daxpy(double *y, double *x, double a, unsigned n){
	unsigned i;
	for(i=0; i<n; i++)
		y[i]+=a*x[i];
}

int main(int argc, char * argv[]){
	unsigned n=10;
	double x[10]={0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
	double y[10]={-1.0,-2.0,-3.0,-4.0,-5.0,-6.0,-7.0,-8.0,-9.0,-10.0};
	const double a=1.5;
	int j;
	struct timespec cgt1,cgt2; double ncgt;
	
	clock_gettime(CLOCK_REALTIME, &cgt1);
	daxpy(y,x,a,n);
	clock_gettime(CLOCK_REALTIME, &cgt2);
	
	for (int j=0; j<10; j++)
		printf("%d  X[]=%g  Y[]=%g\n",j,x[j],y[j]);
		
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	printf("Tiempo: %11.9f\t",ncgt);
	printf("\n");
	
}
