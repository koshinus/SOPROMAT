CC=icc
CFLAGS=-c -Wall
LDFLAGS=
FLAGS=-std=c99 -mkl -openmp -O3 -ipo
SOURCES=main.c simple_omp.c hard_omp.c func.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main.x

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(FLAGS) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(FLAGS) $(CFLAGS) $< -o $@

clean: 
	rm *.o