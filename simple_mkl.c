#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#define EXPERIMENTS_NUM  10
#define ARRAY_SIZE 100000000

void simple_mkl()
{
    /*char *results_file = "simple_mkl.txt";
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
		vdAdd(i, ar1, ar2, ar3);
		vdSub(i, ar1, ar2, ar4);
		vdMul(i, ar1, ar2, ar5);
		vdSqr(i, ar1, ar6);
	}
        double end = omp_get_wtime();
        free(ar1);
        //if(i >= 1000000) printf("free ar1\n");
        free(ar2);
        //if(i >= 1000000) printf("free ar2\n");
        free(ar3);
        //if(i >= 1000000) printf("free ar3\n");
        free(ar4);
        //if(i >= 1000000) printf("free ar4\n");
        free(ar5);
        //if(i >= 1000000) printf("free ar5\n");
        free(ar6);
        //if(i >= 1000000) printf("free ar6\n");
        //fprintf(res, "%lf\n", end-start);
        printf("%lf\n", end-start);
        vslDeleteStream( &stream );
    }
    //fclose(res);
}
