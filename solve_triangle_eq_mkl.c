#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#define ROW 100

double * get_vector(int size, int i)
{
	double *vec;
	VSLStreamStatePtr stream;
	vslNewStream( &stream, VSL_BRNG_MT19937, i*time(0) );
	vec = (double *)calloc(size, sizeof(double));
	vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
	          size, vec, 1.0, 3.0 );
	vslDeleteStream( &stream );
	return vec;
}
                				    
void solve_triangle_eq_mkl()
{
	char *results_file = "solve_triangle_eq_mkl.txt";
	FILE *res;
	if((res=fopen(results_file, "w"))==NULL)
	{
		printf("Can't open file %s.\n", results_file);
		exit(1);
	}
	for(int i = 10; i < ROW; i*=10)
	{
		double *A = get_vector(i*i,i);
		double *X = get_vector(i,i);
		double start = omp_get_wtime();
		cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, i, A, i, X, 1);
		double end = omp_get_wtime();
		fprintf(res, "%lf\n", end-start);
		free(X);free(A);
	}
	fclose(res);
}
