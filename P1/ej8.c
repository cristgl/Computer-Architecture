#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){
	int i,k,l,j;
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
			#pragma omp sections
			{
				#pragma omp section
				for(i=0;i<N/4;i++){
					v1[i] = N*0.1+i*0.1; 
					v2[i] = N*0.1-i*0.1;
				}
				#pragma omp section
				for(j=N/4;j<N/2;j++){
					v1[j] = N*0.1+j*0.1; 
					v2[j] = N*0.1-j*0.1;
				}
				#pragma omp section
				for(k=2*N/4;k<3*N/4;k++){
					v1[k] = N*0.1+k*0.1; 
					v2[k] = N*0.1-k*0.1;
				}
				#pragma omp section
				for(l=3*N/4; l<N;l++){
					v1[l] = N*0.1+l*0.1; 
					v2[l] = N*0.1-l*0.1;
				}
			}
			
			#pragma omp single
			tm1=omp_get_wtime();
			#pragma omp sections
			{
				
				#pragma omp section
				for(i=0;i<N/4;i++){
					v3[i] = v1[i] + v2[i];
				}
				#pragma omp section
				for(j=N/4;j<N/2;j++){
					v3[j] = v1[j] + v2[j];
				}
				#pragma omp section
				for(k=2*N/4;k<3*N/4;k++){
					v3[k] = v1[k] + v2[k];
				}
				#pragma omp section
				for(l=3*N/4; l<N;l++){
					v3[l] = v1[l] + v2[l];
				}
			}
			#pragma omp single
			tm2=omp_get_wtime();
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
