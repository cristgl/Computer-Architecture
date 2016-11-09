#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4096

int main(int argc, char **argv){
	int i, j, k;
	int dimension_matrices;
	int suma;
	suma = 0;

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

	for (i=0; i<dimension_matrices; i++){
		for(j=0; j<dimension_matrices; j++){
			suma = 0;
			for (k=0; k<dimension_matrices; k++){
				suma += (matrizB[i][k]*matrizC[k][j]);
			}
			matrizA[i][j]=suma;
		}
	}

//Imprimimos resultados

	printf ("Resultado[0][0] = %d\n",matrizA[0][0]);
	printf ("Componente(N-1,N-1) del resultado de la multiplicación de ambas matrices=%d\n",matrizA[dimension_matrices-1][dimension_matrices-1]);

//Liberamos las matrices
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}

