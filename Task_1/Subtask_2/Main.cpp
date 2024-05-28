#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <chrono>
using namespace std;

vector<vector<float>> mkl_multiply(vector<vector<float>> i, vector<vector<float>> w,vector<vector<float>> b);
vector<vector<float>> open_multiply(vector<vector<float>> i, vector<vector<float>> w,vector<vector<float>> b);
//vector<vector<float>> pthread_mul(vector<vector<float>> matA, vector<vector<float>> matB,vector<vector<float>> matC);

// this function takes a input text file and converts it into a vector of 2-dimentions as per specified in the text file in coloum major fashion.
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

int main(int argc,char* argv[]) {
    vector<vector<float>> inp;
    vector<vector<float>> weight;
    vector<vector<float>> bias;
    if(argc!= 7){
        throw invalid_argument("Number of arguments mismatch\n");// if fullyconnected is found argc must be 6 else we throw exception
    } 

    if (argv[1] == string("fullyconnected")){
        if (argv[6] == string("mkl")){
            inp = input2d(argv[2]);
            weight = input2d(argv[3]);
            bias = input2d(argv[4]); 
            output2d ( mkl_multiply(inp,weight,bias), argv[5]);
        }
    }
    if (argv[1] == string("fullyconnected")){
        if (argv[6] == string("openblas")){
            inp = input2d(argv[2]);
            weight = input2d(argv[3]);
            bias = input2d(argv[4]); 
            output2d ( open_multiply(inp,weight,bias), argv[5]);
        }
    }
    //if (argv[1] == string("fullyconnected")){
    //    if (argv[6] == string("pthread")){
    //        inp = input2d(argv[2]);
    //        weight = input2d(argv[3]);
    //        bias = input2d(argv[4]); 
    //        output2d ( pthread_mul(inp,weight,bias), argv[5]);
    //    }
    //}
}