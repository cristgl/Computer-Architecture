#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

main(int argc, char **argv) {
	int i, n=200,chunk,a[n],suma=0,chunk2;
	omp_sched_t kind1,kind2=5;
	if(argc < 3) {
		fprintf(stderr,"\nFalta iteraciones o chunk \n");
		exit(-1);
	}
	n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]);
	for (i=0; i<n; i++) a[i] = i;
	#pragma omp parallel 
	{
	#pragma omp for firstprivate(suma) lastprivate(suma) schedule(dynamic,chunk)
		for (i=0; i<n; i++)
			{ suma = suma + a[i];
			printf(" thread %d suma a[%d]=%d suma=%d \n",
			omp_get_thread_num(),i,a[i],suma);
		}
		#pragma omp single
		{

			printf("Antes de modificarlas\n");
			printf("dyn-var %d\n",omp_get_dynamic());
			printf("nthreads-var %d\n", omp_get_max_threads());
			printf("thread-limit-var %d\n", omp_get_thread_limit());
			omp_get_schedule(&kind1,&chunk2);
			printf("run-sched-var kind=%d ", kind2);
			printf("chunk=%d\n", chunk2);

			omp_set_schedule(kind2,chunk);
			omp_set_dynamic(6);
			omp_set_num_threads(7);

			printf("Despues de modificarlas\n");
			printf("dyn-var %d\n",omp_get_dynamic());
			printf("nthreads-var %d\n", omp_get_max_threads());
			printf("thread-limit-var %d\n", omp_get_thread_limit());
			omp_get_schedule(&kind1,&chunk2);
			printf("run-sched-var kind=%d ", kind2);
			printf("chunk=%d\n", chunk2);
		}
	}
	
	printf("Fuera de 'parallel for' suma=%d\n",suma);
}
