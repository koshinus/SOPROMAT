#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#include "func.h"
#define ROW 10000
#define COL 10000

void mat_x_mat_mkl()
{
	/*char *results_file = "mat_x_mat_mkl.txt";
	FILE *res;
	if((res=fopen(results_file, "w"))==NULL)
	{
		printf("Can't open file %s.\n", results_file);
		exit(1);
	}*/
	for(int n = 10; n <= ROW; n*=10)
	{
		for(int m = 10; m <= COL; m*=10)
		{
			double *A = get_vector(m*n,n);
			double *B = get_vector(n*m,m);
			double *C = get_vector(m*m,n*m);
			double start = omp_get_wtime();
			//cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, A, k, B, n, beta, C, n);
			cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, m, n, 1.0, A, n, B, m, 0.0, C, m);
			double end = omp_get_wtime();
			//fprintf(res, "%lf\n", end-start);
			printf("%lf\n", end-start);
			free(A);
			//if(m >= COL) printf("free A\n");
			free(B);
			//if(m >= COL) printf("free B\n");
			free(C);
			//if(m >= COL) printf("free C\n");
		}
	}
	//fclose(res);
}
