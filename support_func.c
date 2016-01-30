#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mkl.h>

double ** get_matrix(int row, int col)
{
    double **mat;
    mat = (double **)malloc(row*sizeof(double*));
    for(int i = 0; i < row; i++)
    {
	VSLStreamStatePtr stream;
	vslNewStream( &stream, VSL_BRNG_MT19937, i*time(0) );
	mat[i] = (double *)malloc(col*sizeof(double));
	vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
	                  col, mat[i], 1.0, 3.0 );
	vslDeleteStream( &stream );
    }
    return mat;
}

double * get_vector(int size, int i)
{
    double *vec;
    VSLStreamStatePtr stream;
    vslNewStream( &stream, VSL_BRNG_MT19937, i*time(0) );
    vec = (double *)malloc(size*sizeof(double));
    vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
			size, vec, 1.0, 3.0 );
    vslDeleteStream( &stream );
    return vec;
}