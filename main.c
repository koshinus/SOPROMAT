#include<stdio.h>
#include"func.h"

int main()
{
    printf("mult_mat_vec_omp:\n");
    mult_mat_vec_omp();
    printf("mult_mat_vec_mkl:\n");
    mult_mat_vec_mkl();
    printf("mat_x_mat_omp:\n");
    mat_x_mat_omp();
    printf("mat_x_mat_mkl:\n");
    mat_x_mat_mkl();
    printf("hard_omp:\n");
    hard_omp();
    printf("hard_mkl:\n");
    hard_mkl();
    printf("simple_omp:\n");
    simple_omp();
    printf("simple_mkl:\n");
    simple_mkl();
    return 0;
}