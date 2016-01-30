#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#define EXPERIMENTS_NUM  10
#define ARRAY_SIZE 1000

void hard_omp()
{
    char *results_file = "hard_omp.txt";
    FILE *res;
    if((res=fopen(results_file, "w"))==NULL)
    {
        printf("Can't open file %s.\n", results_file);
        exit(1);
    }
    for(int i = 10; i < ARRAY_SIZE; i*=10)
    {
	VSLStreamStatePtr stream;
        vslNewStream( &stream, VSL_BRNG_MT19937, i*time(0) );
        double *ar1, *ar2, *ar3, *ar4;
        ar1 = (double *)malloc(i*sizeof(double));
        ar2 = (double *)malloc(i*sizeof(double));
        ar3 = (double *)malloc(i*sizeof(double));
        ar4 = (double *)malloc(i*sizeof(double));
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
                        ARRAY_SIZE, ar1, 1.0, 3.0 );
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
    			ARRAY_SIZE, ar2, 1.0, 3.0 );
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
                        ARRAY_SIZE, ar3, 1.0, 3.0 );
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
                        ARRAY_SIZE, ar4, 1.0, 3.0 );
        double start = omp_get_wtime();
        #pragma omp parallel for
        for(int j = 0; j < EXPERIMENTS_NUM; j++)
        {
    	    #pragma omp parallel for shared(ar1,ar2,ar3,ar4)
            for(int k = 0; k < ARRAY_SIZE; k++)
            {
                ar1[k] = cos(ar1[k]);
                ar2[k] = log(ar2[k]);
                ar3[k] = pow(ar3[k], k%4 - 2);
                ar4[k] = cosh(ar4[k]);
            }
        }
        double end = omp_get_wtime();
        free(ar1); free(ar2); free(ar3); free(ar4);
        fprintf(res, "%lf\n", end-start);
        vslDeleteStream( &stream );
    }
    fclose(res);
}