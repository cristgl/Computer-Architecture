#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4096
int dimension_matrices;
multiplicarMatrices(int **sol, int **p, int **s){
	int i, j, k, suma;
	for (i=0; i<dimension_matrices; i++){
		for(j=0; j<dimension_matrices; j++){
			suma = 0;
			for (k=0; k<dimension_matrices; k++){
				suma += (p[i][k]*s[k][j]);
			}
			sol[i][j]=suma;
		}
	}
}

int main(int argc, char **argv){
	int i, j, k;

	int suma;
	suma = 0;
	struct timespec cgt1,cgt2; double ncgt;
	
	int **matrizB;
	int **matrizC;
	int **matrizA;

	if (argc < 2){
		printf("Falta el número de componentes\n");
		return(1);
	}

    //El producto de matrices cuadradas requiere que ambas sean de la misma
    //dimension por tanto solo necesitamos un parametro para reservar la memoria
	dimension_matrices = atoi(argv[1]);

	if (dimension_matrices > MAX){
		printf("Tamaño demasiado grande. No superar %d\n\n",MAX);
		return(1);
	}

//Creamos las matrices
// matrizA = matrizB * matrizC

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

//Multiplicamos las matrices B y C
clock_gettime(CLOCK_REALTIME, &cgt1);
multiplicarMatrices(matrizA, matrizB, matrizC);
clock_gettime(CLOCK_REALTIME, &cgt2);
//Imprimimos resultados
ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	printf("Tiempo sin optimizar: %11.9f\t",ncgt);
	printf("\n");

	printf ("Resultado[0][0] = %d\n",matrizA[0][0]);
	printf ("Resultado[N-1,N-1]=%d\n",matrizA[dimension_matrices-1][dimension_matrices-1]);

//Liberamos las matrices
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}

