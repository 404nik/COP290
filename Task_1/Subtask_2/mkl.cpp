#include "/usr/include/mkl/mkl.h"
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector<vector<float>> mkl_multiply(vector<vector<float>> i, vector<vector<float>> w,vector<vector<float>> b){
    float *A, *B, *C;
    int m, n, k, p, q;
    float alpha, beta;

    m = i.size(), k = i[0].size(), n = w[0].size();

    alpha = 1.0; beta = 1.0;


    A = (float *)mkl_malloc( m*k*sizeof( float ), 64 );
    B = (float *)mkl_malloc( k*n*sizeof( float ), 64 );
    C = (float *)mkl_malloc( m*n*sizeof( float ), 64 );


    for (int p = 0; p < m; p++)
    {
       for (int q = 0; q < k; q++)
        {
            A[m*q+p] = i[p][q];
        }
    }
    for (int p = 0; p < k; p++)
    {
       for (int q = 0; q < n; q++)
        {
            B[k*q+p] = w[p][q];
        }
    }
    for (int p = 0; p < m; p++)
    {
       for (int q = 0; q < n; q++)
        {
            C[m*q+p] = b[p][q];
        }
    }
    
    cblas_sgemm(CblasColMajor,
				CblasNoTrans, 
				CblasNoTrans, 
				m, 
				n, 
				k, 
				alpha, 
				A, 
				m, 
				B, 
				k, 
				beta, 
				C, 
				m
			);
    
    vector<vector<float>> answer(b.size(),vector<float> (b[0].size(), 0.0f));
    for (int p = 0; p < m; p++)
    {
       for (int q = 0; q < n; q++)
        {
            answer[p][q] = C[(m*q+p)];
        }
    }
    return answer;
}
