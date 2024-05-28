#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
vector<vector<float>> input2d(string x)
{   vector <vector<float>> arr3;
    fstream newfile;
    newfile.open(x,ios::in); //open a file to perform read operation using file object
        if (newfile.is_open()){ //checking whether the file is open
            string a , b;       
            getline(newfile, a);    // first storing the two integers describing the dientions.
            getline(newfile, b);
            int a1 = stoi(a);       // columns,converting string to float.
            int b1 = stoi(b);       //rows
            //vector <vector<float>> arr3 (a1,vector<float>(b1,0));
            for (int x = 0;x< a1;x++){
                vector <float> temp;
                for (int y= 0;y<b1;y++){
                    string tp;
                    (getline(newfile, tp));     // making temp vector to store inner vector in outer. 
                    temp.push_back( stof(tp));
                }
                arr3.push_back(temp);       // pushing the inner vector inside outer 
            }       
      }
      else {
          throw invalid_argument("file not found");
      }
      newfile.close(); //closing the file.
      return arr3; // returning the result .
}

// this function takes a input 2d-vector and creates and writes it in a file x as specified in second argument.
void output2d( vector<vector<float>> arr, string x){
    int a = arr.size();  // a nd b are defined to print the dimentions of the vector/
    int b = arr[0].size();
    fstream newfile;  // opening a filestream 
    newfile.open(x,ios::out);
        if(newfile.is_open()){
            newfile<< a << endl; // writting dimentions.
            newfile<< b << endl;
            for (int i =0 ; i< a ;i++){
                for (int j =0 ; j< b ; j ++){       // writting  the numbers one  after other in new lines 
                    newfile << arr[i][j] << endl;
                }
            }
        }
}

//global variables
int a=0;  //rows of first matrix
int b=0;  //columns of first, rows of second
int c=0;  //columns of second matrix   , matrix c has a*c dimensions
int MAX_THREAD =5;

int x=0;  //coloum number.
 
vector<vector<float>> A;
vector<vector<float>> B;
vector<vector<float>> C;
vector<vector<float>> matD;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* multi(void* arg)
{   
    int q=x; 
    int count=0;
    int temp_number;
    while(count<(c/MAX_THREAD-1) &&  q <= c){
        temp_number=0;
        for(int ro=0;ro<a;ro++){
            temp_number = C[q][ro];
            for (int p=0; p<b; p++){
                temp_number += A[p][ro] * B[q][p];
            }
            pthread_mutex_lock(&(lock));
			matD[q][ro] = temp_number;
			pthread_mutex_unlock(&(lock));
        }
        
        q++;
        count++;
    }

}

vector<vector<float>> pthread_mul(){
    a = A[0].size();     //dening gloabal values.
    b = A.size();        //defining global values.
    c = B.size();        //defining global values.
    vector<vector<float>> temp(a,vector<float>(c,0.0f));
    matD=temp;
    // Creating threads, each evaluating its own part
    pthread_t threads[MAX_THREAD];
     

    for(int i=0; i<MAX_THREAD; i++){
        int* point;
        pthread_create(&threads[i], NULL, multi, (void*)(point));
        x+=c/MAX_THREAD;
       
    }
     
    for (int k = 0;k < MAX_THREAD; k++){
            pthread_join(threads[k], NULL);
    }
    return matD;
}
//int main(){
//  
//    A=input2d("randomMat.txt");
//    B=input2d("randomMat2.txt");
//    C=input2d("randomMat3.txt");
//     
//    vector<vector<float>>D=pthread_mul();
//
//    output2d(D,"answer.txt");
//    return 0;
//}