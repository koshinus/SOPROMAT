#include <stdio.h>
#include <stdlib.h>
#include <mkl.h>
#include <mkl_cblas.h>
#include <mkl_blas.h>
#include <mkl_lapack.h>
#include <mkl_lapacke.h>

int main()
{
	/*double A[3][3] = {{1, 1, 1}, 
			  {0, 1, 1}, 
			  {0, 0, 1}};
	double B[2][3] = {{1, 1, 1}, 
			  {1, 1, 1}};
	*/
	double *A = (double *)calloc(3*3, sizeof(double));
	double *B = (double *)calloc(2*3, sizeof(double));
	for(int i = 0; i < 2; i++)
	    for(int j = 0; j < 3; j++) B[j+i*3] = 1.0;
	for(int i = 0; i < 3; i++)
	    for(int j = 0; j < 3; j++)
	    {
		if(i <= j) A[j+i*3] = 1.0;
	    }
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit, 2, 3, 1.0, A, 3, B, 3);
	for(int i = 0; i < 2; i++)
	{
	    for(int j = 0; j < 3; j++) printf("%lf ", B[j+i*3]);
	    printf("\n");
	}
}