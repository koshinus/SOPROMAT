#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#include "func.h"
#define ROW 1000
#define COL 1000
                				    
void mult_mat_vec_omp()
{
	/*char *results_file = "mult_mat_vec_omp.txt";
	FILE *res;
	if((res=fopen(results_file, "w"))==NULL)
	{
		printf("Can't open file %s.\n", results_file);
		exit(1);
	}*/
	for(int i = 10; i < ROW; i*=10)
	{
		for(int j = 10; j < COL; j*=10)
		{
			double **A = get_matrix(i,j);
			double 	*X = get_vector(j,i*j);
			double 	*Y = (double *)calloc(i,sizeof(double));
			double start = omp_get_wtime();
			#pragma omp parallel for collapse(2)
			for(int s = 0; s < i; s++)
				for(int t = 0; t < j; t++)
					Y[s] += A[s][t]*X[t];
			double end = omp_get_wtime();
			//fprintf(res, "%lf\n", end-start);
			printf("%lf\n", end-start);
			free(X); free(Y);
			for(int s = 0; s < i; s++)
				free(A[s]);
			free(A);
		}
	}
	//fclose(res);
}
