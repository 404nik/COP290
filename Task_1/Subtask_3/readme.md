# COP Assignment 1 Task 3

## Overview

In this task, OpenBLAS library is utilized for computation purposes in a row-fashioned manner. Additionally, instead of vectors, pointer to arrays is used, differing from Task 2 of the assignment.

### Functions Defined in `main.cpp`

- The function `open_multiply` takes the input matrix, weight matrix, and bias matrix. It computes the product of the input and weight matrices, adds the bias matrix to it, and updates the result matrix passed as an argument.
- `takeInput1` function reads input from an input file where float numbers are separated by a single space and stores them in an array in a row-fashioned form.
- `takeInput2` function reads inputs from `weight1.txt`, `weight2.txt`, `weight3.txt`, `bias1.txt`, `bias2.txt`, `bias3.txt`, and stores them in an array.
- `softmax` and `relu` functions compute the probability as defined in the guidelines and make negative terms zero, respectively.
- The `topthree` function takes an input file `inputstr`, `pred` array, and `anserr` array, computes the top three words with the highest probabilities, and updates the `pred` array as per the guidelines.
- Finally, the `libaudioPI` function takes the file to be computed over and `pred` array. It performs computations as per the guidelines, computes the ReLU function on matrices, and applies the softmax function to the final 1*12 matrix. The `topthree` function is then called to find the words with the highest probabilities.

### `run.cpp`

- It checks if `./yourcode.out audiosamplefile outputfile.txt` is passed correctly and ensures there are no mismatches in the number of arguments.
- The `libaudioAPI` function is called, passing it the input file and `pred` array defined in the same section.
- Finally, the desired result is output using `ofstream` in the `outputfile.txt`.

### How to Run the Code

- Update the path of the directory in the Makefile.
- Compile the code by typing the command `make` in the terminal to compile the code and create the executable `yourcode.out`.
- Link the library and export it using the following commands:

```sh
LD_LIBRARY_PATH=/home/mehul/project3:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/mehul/project3:$LD_LIBRARY_PATH
```

- Replace `/home/mehul/project3` with the actual path of the directory where the files are stored.
- Run the code for `inputfile.txt` and append the result to `outputfile.txt` using the command:

```sh
./yourcode.out inputfile.txt outputfile.txt
```

- If this is called again provided the `outputfile` remains the same, the result will be appended to a new line in this file.
- Instead of `inputfile.txt` and `outputfile.txt`, use the complete file path for them if necessary.