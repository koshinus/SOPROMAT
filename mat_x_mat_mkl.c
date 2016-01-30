#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#include "func.h"
#define ROW 100
#define COL 100

void mat_x_mat_mkl()
{
	/*char *results_file = "mat_x_mat_mkl.txt";
	FILE *res;
	if((res=fopen(results_file, "w"))==NULL)
	{
		printf("Can't open file %s.\n", results_file);
		exit(1);
	}*/
	for(int n = 10; n < ROW; n*=10)
	{
		for(int m = 10; m < COL; m*=10)
		{
			double *A = get_vector(m*n,n);
			double *B = get_vector(n*m,m);
			double *C = get_vector(m*m,n*m);
			double start = omp_get_wtime();
			//cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, A, k, B, n, beta, C, n);
			cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, m, 1.0, A, m, B, n, 0.0, C, n);
			double end = omp_get_wtime();
			//fprintf(res, "%lf\n", end-start);
			printf("%lf\n", end-start);
			free(A); free(B); free(C);
		}
	}
	//fclose(res);
}
