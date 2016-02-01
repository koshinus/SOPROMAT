#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#define EXPERIMENTS_NUM  10
#define ARRAY_SIZE 100000000

void hard_omp()
{
    /*char *results_file = "hard_omp.txt";
    FILE *res;
    if((res=fopen(results_file, "w"))==NULL)
    {
        printf("Can't open file %s.\n", results_file);
        exit(1);
    }*/
    for(int i = 10; i <= ARRAY_SIZE; i*=10)
    {
	VSLStreamStatePtr stream;
        vslNewStream( &stream, VSL_BRNG_MT19937, i*time(0) );
        double *ar1, *ar2, *ar3, *ar4, *ar5, *ar6;
        ar1 = (double *)malloc(i*sizeof(double));
        ar2 = (double *)malloc(i*sizeof(double));
        ar3 = (double *)malloc(i*sizeof(double));
        ar4 = (double *)malloc(i*sizeof(double));
        ar5 = (double *)malloc(i*sizeof(double));
        ar6 = (double *)malloc(i*sizeof(double));
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
                	i, ar1, 1.0, 3.0 );
        vdRngGaussian( VSL_RNG_METHOD_GAUSSIAN_BOXMULLER, stream,
    			i, ar2, 1.0, 3.0 );
        double start = omp_get_wtime();
        for(int j = 0; j < EXPERIMENTS_NUM; j++)
        {
    	    #pragma omp parallel for shared(ar1,ar2,ar3,ar4,ar5,ar6)
            for(int k = 0; k < i; k++)
            {
                ar3[k] = cos(ar1[k]);
                ar4[k] = log(ar2[k]);
                ar5[k] = pow(ar1[k], ar2[k]);
                ar6[k] = cosh(ar1[k]);
            }
        }
        double end = omp_get_wtime();
        free(ar1); free(ar2); free(ar3); free(ar4); free(ar5); free(ar6);
        //fprintf(res, "%lf\n", end-start);
        printf("%lf, i=%d\n", end-start, i);
        vslDeleteStream( &stream );
    }
    //fclose(res);
}