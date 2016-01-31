#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#include "func.h"
#define ROW 10000
#define COL 10000
                				    
void mult_mat_vec_mkl()
{
	/*char *results_file = "mult_mat_vec_mkl.txt";
	FILE *res;
	if((res=fopen(results_file, "w"))==NULL)
	{
		printf("Can't open file %s.\n", results_file);
		exit(1);
	}*/
	for(int i = 10; i <= ROW; i*=10)
	{
		for(int j = 10; j <= COL; j*=10)
		{
			double *A = get_vector(i*j,i);
			double *X = get_vector(j,i*j);
			double *Y = (double *)calloc(i,sizeof(double));
			double start = omp_get_wtime();
			cblas_dgemv(CblasRowMajor, CblasNoTrans, i, j, 1.0, A, j, X, 1, 1.0, Y, 1);
			double end = omp_get_wtime();
			//fprintf(res, "%lf\n", end-start);
			printf("%lf\n", end-start);
			free(X); free(Y); free(A);
		}
	}
	//fclose(res);
}