#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
	int a;
	int b;
} s[5000];

main(){
	int X1=0, X2=0, X1a, X1b, X1c, X1d, X2a, X2b, X2c, X2d, R[39999], ii, i;
	struct timespec cgt1,cgt2; double ncgt;
	for(i=0; i<5000; i++){
		s[i].a=0;
		s[i].b=0;
	}
	clock_gettime(CLOCK_REALTIME, &cgt1);
	for (ii=0; ii<40000;ii++) {
		X1a=0;X1b=0;X1c=0;X1d=0; X2a=0;X2b=0;X2c=0;X2d=0;
		for(i=0; i<5000;i+=4){
			X1a+=2*s[i].a+ii;
			X1b+=2*s[i+1].a+ii;
			X1c+=2*s[i+2].a+ii;
			X1d+=2*s[i+3].a+ii;
		}
		for(i=0; i<5000;i+=4){
			X2a+=3*s[i].b-ii;
			X2b+=3*s[i+1].b-ii;
			X2c+=3*s[i+2].b-ii;
			X2d+=3*s[i+3].b-ii;
		}
		X1=X1a+X1b+X1c+X1d;
		X2=X2a+X2b+X2c+X2d;
		if (X1<X2) 
			R[ii]=X1;
		else 
			R[ii]=X2;
	}
	clock_gettime(CLOCK_REALTIME, &cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	printf("Tiempo optimizado: %11.9f\t",ncgt);
	printf("\n");
	printf("Resultado[0] %d\n",R[0]);
	printf("Resultado[39999] %d\n",R[39999]);

}
