#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <mkl.h>
#include "func.h"
#define ROW 10000
#define COL 10000
            		        
            		        void mat_x_mat_omp()
            		        {
            		    	/*char *results_file = "mat_x_mat_omp.txt";
            		    	    FILE *res;
            		    		if((res=fopen(results_file, "w"))==NULL)
            		    		    {
            		    			    printf("Can't open file %s.\n", results_file);
            		    				    exit(1);
            		    					}*/
            		    					    for(int n = 10; n <= ROW; n*=10)
            		    						{
            		    							for(int m = 10; m <= COL; m*=10)
            		    								{
            		    									    double **A = get_matrix(m,n);
            		    											double **B = get_matrix(n,m);
            		    												    double **C = (double **)malloc(m*sizeof(double*));
            		    														for(int s = 0; s < m; s++)
            		    																C[s] = (double *)calloc(m,sizeof(double));
            		    																	    double start = omp_get_wtime();
            		    																			#pragma omp parallel for collapse(3)
            		    																				    for (int i = 0; i < m; i++)
            		    																						    for (int j = 0; j < m; j++)
            		    																									for (int k = 0; k < n; k++)
            		    																												C[i][j] += A[i][k]*B[k][j];
            		    																													    double end = omp_get_wtime();
            		    																															//fprintf(res, "%lf\n", end-start);
            		    																																    printf("%lf, n*m=%d*%d\n", end-start, n, m);
            		    																																		for(int s = 0; s < m; s++)
            		    																																			    {
            		    																																					    free(A[s]);
            		    																																							    free(C[s]);
            		    																																									}
            		    																																										    for(int s = 0; s < n; s++)
            		    																																												    free(B[s]);
            		    																																														free(A); free(B); free(C);
            		    																																															}
            		    																																															    }
            		    																																																//fclose(res);
            		    																																																}
            		    																																																