#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4096
int dimension_matrices;
multiplicarMatrices(int **sol, int **p, int **s){
	int i, j, k, suma1,suma2,suma3,suma4;
	for (i=0; i<dimension_matrices; i++){
		suma1 = 0;suma2 = 0;suma3 = 0;suma4 = 0;
			for (k=0; k<dimension_matrices; k+=4){
				suma1 += (p[i][k]*s[k][j]);
				suma2 += (p[i][k+1]*s[k+1][j]);
				suma3 += (p[i][k+2]*s[k+2][j]);
				suma4 += (p[i][k+3]*s[k+3][j]);
			}
			sol[i][j]=suma1+suma2+suma3+suma4;
	}
}


int main(int argc, char **argv){
	int i, j, k;
	int dimension_matrices;
	int suma1,suma2,suma3,suma4;
	
	struct timespec cgt1,cgt2; double ncgt;
	
	int **matrizB;
	int **matrizC;
	int **matrizA;

	if (argc < 2){
		printf("Falta el número de componentes\n");
		return(1);
	}

  
	dimension_matrices = atoi(argv[1]);

	if (dimension_matrices > MAX){
		printf("Tamaño demasiado grande. No superar %d\n\n",MAX);
		return(1);
	}


	matrizB = (int **)malloc(dimension_matrices * sizeof(int*));
	matrizC = (int **)malloc(dimension_matrices * sizeof(int*));
	matrizA = (int **)malloc(dimension_matrices * sizeof(int*));

	for (i=0; i<dimension_matrices; i++){
		matrizB[i] = (int *)malloc(dimension_matrices * sizeof(int));
		matrizC[i] = (int *)malloc(dimension_matrices * sizeof(int));
		matrizA[i] = (int *)malloc(dimension_matrices * sizeof(int));
	}

//Inicializamos las matrices

	for (j=0; j<dimension_matrices; j++){
		for (i=0; i<dimension_matrices; i++){
			matrizB[j][i] = j+i;
			matrizC[j][i] = j*i;
		}
	}



clock_gettime(CLOCK_REALTIME, &cgt1);
multiplicarMatrices(matrizA,matrizB,matrizC);
clock_gettime(CLOCK_REALTIME, &cgt2);

ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	printf("Tiempo optimizado: %11.9f\t",ncgt);
	printf("\n");

	printf ("Resultado[0][0] = %d\n",matrizA[0][0]);
	printf ("Resultado[N-1,N-1]=%d\n",matrizA[dimension_matrices-1][dimension_matrices-1]);


	for(i=0; i<dimension_matrices; i++)
		free(matrizA[i]);
    free(matrizA);
for(i=0; i<dimension_matrices; i++)
		free(matrizB[i]);
    free(matrizB);
for(i=0; i<dimension_matrices; i++)
		free(matrizC[i]);
    free(matrizC);

    return 0;
}

