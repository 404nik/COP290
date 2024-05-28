CC=g++
CFLAGS= -o

all:
	$(CC) -I /usr/include/mkl -L /usr/include/mkl/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lm -ldl -fopenmp -I /usr/include/x86_64-linux-gnu/openblas-pthread/ -L /usr/include/x86_64-linux-gnu/ -lopenblas -lpthread -lgfortran -pthread openblas.cpp mkl.cpp Main.cpp $(CFLAGS) yourcode.out

clean:
	-rm*.out
