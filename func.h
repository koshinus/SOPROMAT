#ifndef _FUNC_H_
#define _FUNC_H_

void hard_omp();
void simple_omp();
void hard_mkl();
void simple_mkl();
void mult_mat_vec_omp();
void mult_mat_vec_mkl();
void mat_x_mat_mkl();
void mat_x_mat_omp();
void hard_no_omp();
void simple_no_omp();
double *  get_vector(int size, int i);
double ** get_matrix(int row, int col);

#endif