#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
main(int argc, char **argv) {
	int i,j,N,m;
	if(argc < 2) {
			fprintf(stderr,"Falta componentes\n");
			exit(-1);
	}
	N=atoi(argv[1]);
		int* V1 = (int*) malloc(N*sizeof(int));// malloc necesita el tamaño en bytes
	int* V2 = (int*) malloc(N*sizeof(int)); //si no hay espacio suficiente malloc devuelve NULL
	int ** M = (int**) malloc(N*sizeof(int*));
	for(i=0; i<N; i++)
		M[i] = (int*) malloc(N*sizeof(int));
	
	for (i=0; i<N; i++) V1[i] = i;
	for (i=0; i<N; i++) V2[i] = 0;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			M[i][j]=j;
	#pragma omp parallel for private(m) private(j)
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			m+=M[i][j]*V1[j];
			
		}V2[i]=m;
	}
		
	for(i=0; i<N; i++)
		printf("%d\n",V2[i]);
			
	free(V1);
	free(V2);
	for(i=0; i<N; i++)
		free(M[i]);
	free(M);
}
