#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv) {
	if(argc<2){
		fprintf(stderr,"\nFalta numero de filas/columnas \n");
		exit(-1);
	}
	int i,j;
	int VAR=atoi(argv[1]);
	int *V1 = (int*) malloc(VAR*sizeof(int));
	int *V2 = (int*) malloc(VAR*sizeof(int));
	int **M = (int**) malloc(VAR*sizeof(int*));

	for(j=0; j<VAR; j++)
		M[j] = (int*) malloc(VAR*sizeof(int));

	for(i=0; i<VAR; i++)
		V1[i]=i+1;
	printf("Vector inicializado\n");
	for(i=0; i<VAR; i++)
		printf("%d ",V1[i]);
	printf("\n");
	for(i=0; i<VAR; i++) // triangular inferior
		for(j=0;j<=i; j++)
			M[i][j]=j+1;
	printf("Matriz inicializada\n");
	for(i=0; i<VAR; i++){
		printf("\n");
		for(j=0; j<VAR; j++)
			printf("%d ",M[i][j]);
	}
	printf("\n");
	for(i=0;i<VAR; i++)
		for(j=0;j<=i; j++)
			V2[i]+=M[i][j]*V1[j];
	printf("Vector final\n");
	for(j=0; j<VAR; j++)
		printf("%d\n",V2[j]);

	free(V1);
	free(V2);
	for(i=0; i<VAR; i++)
		free(M[i]);
	free(M);

}
