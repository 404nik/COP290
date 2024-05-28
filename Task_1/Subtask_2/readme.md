# COP Assignment Stage 2

## Overview

In this stage, we have defined three functions for evaluating the resultant matrix of the fully connected function using three different C++ libraries:

1. **OpenBLAS**
2. **MKL (Math Kernel Library)**
3. **Pthread**

## Compilation

To compile the code, you can use the following command:

```sh
g++ -I /usr/include/mkl -L /usr/include/mkl/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lm -ldl -fopenmp -I /usr/include/x86_64-linux-gnu/openblas-pthread/ -L /usr/include/x86_64-linux-gnu/ -lopenblas -lpthread -lgfortran -pthread openblas.cpp mkl.cpp main.cpp -o yourcode.out
```

Alternatively, you can use the `make` command to compile the program.

## Execution

To execute the instructions and call the functions, use the following commands:

### Pthread Method

To compute using the pthread method:

```sh
./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt output.txt pthread
```

### MKL Method

To compute using the MKL method:

```sh
./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt output.txt mkl
```

### OpenBLAS Method

To compute using the OpenBLAS method:

```sh
./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt output.txt openblas
```

## Deviation and Boxplots

- **Deviation Plot for MKL Method**: `dev_mkl.png`
- **Deviation Plot for OpenBLAS Method**: `dev_open.png`
- **Boxplot for MKL Method**: `mkl_boxplot.png`
- **Boxplot for OpenBLAS Method**: `open_boxplot.png`
- **EPS for MKL Method**: `mkl_boxplot.eps`
- **EPS for OpenBLAS Method**: `open_boxplot.eps`

Ensure that all input files are correctly named and placed in the appropriate directory before running the commands. Use the plots to analyze the performance and deviations of the different methods.