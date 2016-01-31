#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10000000

int main()
{
    double *ar1 = (double *)malloc(ARRAY_SIZE*sizeof(double));
    double *ar2 = (double *)malloc(ARRAY_SIZE*sizeof(double));
    srand(time(0));
    //printf("ok!\n");
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
	ar1[i] = (rand()%(i+1)+1)/(rand()%(i+1)+2);
	ar2[i] = (rand()%(i+1)+1)/(rand()%(i+1)+2);
	printf("%lf\n", ar1[i]+ar2[i]);
    }
    free(ar1); free(ar2);
    return 0;
}