#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
main(int argc, char **argv) {
	int i,j,N, V1[N], V2[N], M[N][N];
	if(argc < 2) {
			fprintf(stderr,"Falta componentes\n");
			exit(-1);
	}
	N=atoi(argv[1]);
	
	
	for (i=0; i<N; i++) V1[i] = i;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			M[i][j]=j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			V2[i]+=M[i][j]*V1[j];
		
	for(i=0; i<N; i++)
		printf("%d\n",V2[i]);
		
		
			/*int* V1 = (int*) malloc(N*sizeof(int));// malloc necesita el tamaño en bytes
	int* V2 = (int*) malloc(N*sizeof(int)); //si no hay espacio suficiente malloc devuelve NULL
	int ** M = (int**) malloc(N*sizeof(int*));
	for(i=0; i<N; i++)
		M[i] = (int*) malloc(N*sizeof(int));*/
	/*
	free(V1);
	free(V2);
	for(i=0; i<N; i++)
		free(M[i]);
	free(M);*/
	/*		
	#pragma omp for private(j)
	for(i=0;i<N;i++){ //esta es la que se convierte en privada por defecto
		for(j=0;j<N;j++) //si la hubiesemos declarado dentro del parallel sería privada en toda la región paralela
			v2[i]+=M[i][j]*v1[j];*/
}
