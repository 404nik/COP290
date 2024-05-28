# COP290 Project 1

## Subtask 1: Warming up to Compiling and Debugging C++ Functions

This project involves implementing and testing various C++ functions. Follow the instructions below to compile and run the functions.

### Compilation

To compile the code, use the command:

```sh
make
```

### Execution

Once compiled, the functions can be accessed with the following commands:

#### A. Fully Connected Function

To compute the fully connected function, use:

```sh
./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt
```

- `inputmatrix.txt`: The first matrix file
- `weightmatrix.txt`: The second matrix file
- `biasmatrix.txt`: The third matrix file
- `outputmatrix.txt`: The output matrix file that will be created

#### B. Max Pooling Function

To compute the max pooling function, use:

```sh
./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt
```

- `inputmatrix.txt`: The input matrix file
- `stride`: The integer stride value
- `outputmatrix.txt`: The output matrix file that will be created

#### C. Average Pooling Function

To compute the average pooling function, use:

```sh
./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt
```

- `inputmatrix.txt`: The input matrix file
- `stride`: The integer stride value
- `outputmatrix.txt`: The output matrix file that will be created

#### D. Sigmoid Function

To compute the sigmoid function, use:

```sh
./yourcode.out probability sigmoid inputvector.txt outputvector.txt
```

- `inputvector.txt`: The input vector file
- `outputvector.txt`: The output vector file that will be created

#### E. Softmax Function

To compute the softmax function, use:

```sh
./yourcode.out probability softmax inputvector.txt outputvector.txt
```

- `inputvector.txt`: The input vector file
- `outputvector.txt`: The output vector file that will be created

#### F. ReLU Function

To compute the ReLU function, use:

```sh
./yourcode.out activation relu inputmatrix.txt outputmatrix.txt
```

- `inputmatrix.txt`: The input matrix file
- `outputmatrix.txt`: The output matrix file that will be created

#### G. Tanh Function

To compute the tanh function, use:

```sh
./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt
```

- `inputmatrix.txt`: The input matrix file
- `outputmatrix.txt`: The output matrix file that will be created

### Error Handling

- **File Not Found**: If any input file is not found, you will receive a "File not found error."
- **Argument Mismatch**: If the command contains more or fewer arguments than required, "Number of arguments mismatch" will be printed.
- **Invalid Operation**: If an undefined operation is passed (e.g., `rulu` instead of `relu`), you will receive an "Invalid operation for argv[1]" error.

Ensure that all input files are correctly named and placed in the appropriate directory before running the commands.

For more details about the course, visit the [course webpage](https://www.cse.iitd.ac.in/~rijurekha/cop290_2022.html).