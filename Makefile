CC=icc
CFLAGS=-c -Wall
LDFLAGS=
FLAGS=-std=c99 -mkl -openmp -O3 -ipo -mmic
SOURCES=main.c simple_omp.c simple_mkl.c hard_omp.c hard_mkl.c hard_no_omp.c simple_no_omp.c mult_mat_vec_mkl.c mult_mat_vec_omp.c support_func.c mat_x_mat_mkl.c mat_x_mat_omp.c func.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main.x

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(FLAGS) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(FLAGS) $(CFLAGS) $< -o $@

clean: 
	rm *.o