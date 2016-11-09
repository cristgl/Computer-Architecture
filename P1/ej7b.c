#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){
	int i;
	if (argc<2){
		printf("Faltan nº componentes del vector\n");
		exit(-1);
	}
	double tm,tm1,tm2;
	unsigned int N = atoi(argv[1]);

	double *v1, *v2, *v3;

	v1 = (double*) malloc(N*sizeof(double));// malloc necesita el tamaño en bytes
	v2 = (double*) malloc(N*sizeof(double)); //si no hay espacio suficiente malloc devuelve NULL
	v3 = (double*) malloc(N*sizeof(double));
	if ( (v1==NULL) || (v2==NULL) || (v3==NULL) ){
		printf("Error en la reserva de espacio para los vectores\n");
		exit(-2);
	}
		#pragma omp parallel
		{
		#pragma omp for
		for(i=0; i<N; i++){
			v1[i] = N*0.1+i*0.1; 
			v2[i] = N*0.1-i*0.1;
		}
		#pragma omp master
		tm1=omp_get_wtime();
		#pragma omp barrier
		#pragma omp for //calculando suma
		for(i=0; i<N; i++)
			v3[i] = v1[i] + v2[i];
		#pragma omp master
		tm2=omp_get_wtime();
		#pragma omp barrier
		}
			
	
	tm=(tm2-tm1);
	printf("Tiempo(seg.):%f\t / Tamaño Vectores:%u\n",tm,N);
	for(i=0;i<N;i++)
		printf("%f\t",v3[i]);
			
	free(v1);
	free(v2);
	free(v3);		
	
	return 0;
}
