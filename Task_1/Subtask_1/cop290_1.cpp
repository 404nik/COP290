#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
//  helper function for fullyconnected takes 3 input 2d-vectors and generates resultant 2-d vector. multiplation is done in coloum major fashion only.
vector<vector<float>> sum_add_matrix(vector <vector<float>> arr1 , vector <vector<float>> arr2,vector <vector<float>> arr4){
    int i , j ,k, a, b, c;
     a= arr1[0].size(); // rows of inp matrix 
     b= arr2[0].size(); // rows of weitage 
     c= arr2.size(); // coloums of weitage
     vector <vector<float>> arr3 (c,vector<float>(a,0.0f));
    for (j=0; j<a ;j++){
        for (i=0 ;i<c;i++){
            for (k=0;k<b;k++){
            arr3[j][i] += arr1[k][i]* arr2[j][k] ;
            }
            arr3[j][i] += arr4[j][i];
        }
        
    }
    return arr3; // returning the resultant

}

//  helper function for relu takes 1 input 2d-vector and generates resultant 2-d vector.
vector<vector<float>> relu_1(vector <vector<float>> arr){
    int i,j;
    vector <vector<float>> arr_res (arr.size(),vector<float>(arr[0].size(),0.0f));
    for (i = 0 ; i < arr.size() ; i++){
        for (j=0 ;j<arr[0].size(); j++){
            arr_res[i][j] = max(0.0f,arr[i][j]); // using max fuction for find maximum 
        }
    }
   
    return arr_res; // returning the resultant
}

// helper function for tanh takes 1 input 2d-vector and generates resultant 2-d vector.
vector<vector<float>> tan_h(vector <vector<float>> arr){
    int i,j;
    vector <vector<float>> arr_res(arr.size(),vector<float>(arr[0].size(),0.0f));
    for (i = 0 ; i < arr.size() ; i++){
        for (j=0 ;j<arr[0].size(); j++){
            arr_res[i][j] = (exp(2*arr[i][j])-1)/(exp(2*arr[i][j])+1); // formula for computing tanh for each element of the input 2-d vector.
        }
    }
    return arr_res; // returning the resultant
}

// helper function for tanh takes 1 input 1d-vector and generates resultant 1d vector.
vector<float> sigmoidd(vector<float> arr){
    int i;
    vector<float> arr_res(arr.size(),0.0f);
    for (i = 0 ; i < arr.size() ; i++){
            arr_res[i] = (1)/(1+(exp(-arr[i])));     // formula for sigmoid fuction using exp 
    }
    return arr_res; // returning the resultant 
}

// helper function for softmax takes 1 input 1d-vector and generates resultant 1d vector.
vector<float> softmaxx(vector<float> arr){
    int i, j ;
    float sum = 0.0f;
    vector<float> arr_res(arr.size(),0.0f);
    for (j = 0 ; j<arr.size(); j ++){
        sum += exp(arr[j]); // calculating the deominator sum 
    }
    for (i = 0 ; i < arr.size() ; i++){
            arr_res[i] = exp(arr[i])/sum; // calculating the probability.
            
    }
    return arr_res;// returning the resultant 
}

// helper function for maxpooling takes 1 input 2d-vector ,integer stride and  generates resultant 2d  diminished vector.
vector<vector<float>> max_pooling(vector <vector<float>> arr, int stride ){
    int f = arr.size()/stride;
    vector<vector<float>> res(f,(vector<float>(f,0.0f)));
    for (int i = 0; i<arr.size(); i+=stride){  // running two outer for loops to compute final matrix 
        for (int j= 0 ; j< arr[0].size();j += stride){
            res[i/stride][j/stride] = arr[i][j];
            for (int k =i ; k<i+stride;k++){  // running the inner for loops for compute the maximum element of the stride square.
                for (int l= j; l<j+stride;l++){
                    res[i/stride][j/stride]= max(arr[k][l],res[i/stride][j/stride]);//using max function to compute maximum. 
                }
            }
     
        }
    }
    return res;// returning the resultant
}

// helper function for maxpooling takes 1 input 2d-vector ,integer stride and  generates resultant 2d  diminished vector.
vector<vector<float>> avg_pooling(vector <vector<float>> arr, int stride ){
    int f = arr.size()/stride;
    vector<vector<float>> res(f,(vector<float>(f,0.0f)));
    for (int i = 0; i<arr.size(); i+=stride){       // running two outer for loops to compute final matrix 
        for (int j= 0 ; j< arr[0].size();j += stride){
            for (int k =i ; k<i+stride;k++){        // running the inner for loops for compute the maximum element of the stride square.
                for (int l= j; l<j+stride;l++){
                    res[i/stride][j/stride] +=arr[k][l];
                }
            }
            float temp = res[i/stride][j/stride];   //using temp variable to compute average of the stride square.
            res[i/stride][j/stride] = temp/4;
        }
    }
    return res;// returning the resultant
}

// this function takes a input text file and converts it into a vector of 2-dimentions as per specified in the text file in coloum major fashion.
vector<vector<float>> input2d(string x)
{   vector <vector<float>> arr3;
    fstream newfile;
    newfile.open(x,ios::in); //open a file to perform read operation using file object
        if (newfile.is_open()){ //checking whether the file is open
            string a , b;       
            getline(newfile, a);    // first storing the two integers describing the dientions.
            getline(newfile, b);
            int a1 = stoi(a);       // converting string to float.
            int b1 = stoi(b);
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

// this function takes a input text file and converts it into a vector of 1-dimentions as per specified in the text file .
// it follows the similar proccess as described above 
vector<float> input1d(string x)
{   vector <float> arr3;
    fstream newfile;
    newfile.open(x,ios::in); 
        if (newfile.is_open()){ 
            string a;
            getline(newfile, a);
            int a1 = stoi(a);
            for (int x = 0;x< a1;x++){
                    string tp;
                    (getline(newfile, tp));
                    arr3.push_back (stof(tp));
            }    
            newfile.close();
      }
      else {
          throw invalid_argument("file not found");
      }
      return arr3;
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

// this function takes a input 1d-vector and creates and writes it in a file x as specified in second argument.
// It follows similar process as described for output2d function.
void output1d( vector<float> arr, string x){
    int a = arr.size();
    fstream newfile;
    newfile.open(x,ios::out);
        if(newfile.is_open()){
            newfile<< a << endl;
            for (int i =0 ; i< a ;i++){
                newfile << arr[i] << endl;
            }
        }

}

// final maxpooling function which prints output on file y taking input file x and help of int stride ,output 2d , input2d and max_pooling.
void maxpooling(string x, string y , int stride ){
  output2d(max_pooling((input2d(x)),stride),y);
}

// final avgpooling function which prints output on file y taking input file x and help of int stride ,output 2d , input2d and avg_pooling.
void avgpooling(string x, string y , int stride){
    output2d(avg_pooling((input2d(x)),stride),y);
}

// final fullyconnected function which prints output on file out taking input file x , y and z taking help of output 2d , input2d  and sum_add_matrix  .
void fullyconnected(string x , string y ,string z , string out){
    output2d(sum_add_matrix(input2d(x),input2d(y),input2d(z)),out);
}

// final sigmoid function which prints output on file y taking input file x  and taking help of functions output1d , sigmoidd, input1d  .
void sigmoid(string x , string y  ){
    output1d(sigmoidd(input1d(x)),y);
}

// final softmax function which prints output on file y taking input file x  and taking help of functions output1d , softmaxx, input1d  .
void softmax(string x , string y){
    output1d(softmaxx(input1d(x)),y);
}

// final tanh function which prints output on file y taking input file x and help of int  output 2d , input2d and tan_h.
void tanh(string x , string y ){
    output2d(tan_h(input2d(x)),y);
}

// final relu function which prints output on file y taking input file x and help of int  output 2d , input2d and relu_1.
void relu(string x , string y ){
    output2d(relu_1(input2d(x)),y);
}

// we use here argc to find number of arguments passed and argv to find the n th argumnet 
int main(int argc,char* argv[])
{  
    if (argv[1] == string("activation")){
       if (argc != 5){
           throw invalid_argument("Number of arguments mismatch\n"); // if activation is found argc must be 5 else we throw exception 
       }
       else {
           string decide = argv[2];
           if(decide == string("relu")){
                string in=argv[3];
                string out=argv[4];
                relu(in , out);
           }
           else if (decide == string("tanh")){
                string in=argv[3];
                string out=argv[4];
                tanh(in,out);
           }
           else throw invalid_argument("Invalid operation of activation\n");
       }
    }
    else if (argv[1] == string("pooling")){
        if (argc != 6){
           throw invalid_argument("Number of arguments mismatch\n");// if pooling is found argc must be 6 else we throw exception
       }
       else {
           if (argv[2] == string("average")){// next if we find average we return output file from avgpooling function passing suitable parameters specified.
               string in = argv[3];
               string out = argv[5];        // setting string for simplicity 
               int str = stoi(argv[4]);
               avgpooling(in,out,str);      // returning resultant function 
           }
           else if(argv[2] == string("max")){// next if we find maxpooling we return output file from maxpooling function passing suitable specified arguments..
               string in = argv[3];
               string out = argv[5];        // setting string for simplicity 
               int str = stoi(argv[4]);
               maxpooling(in,out,str);  // returning resultant function 
           }
           else throw invalid_argument("Invalid operation of pooling\n");
       }
    }
    else if (argv[1] == string ("probability")){
        if(argc!= 5){
            throw invalid_argument("Number of arguments mismatch\n");// if probability is found argc must be 5 else we throw exception
        }
        else {
            if (argv[2] == string("sigmoid")){
                sigmoid (argv[3],argv[4]); // next if we find sigmoid we return output file from sigmoid function.
            }
            else if (argv[2] == string("softmax")){
                softmax(argv[3],argv[4]);// next if we find softmax we return output file from sigmoid function.
            }
            else throw invalid_argument("Invalid operation of probability\n"); // if both are not found in probabitlity domain we throw another error.
        }
    }
    else if (argv[1] == string("fullyconnected")){
        if(argc!= 6){
            throw invalid_argument("Number of arguments mismatch\n");// if fullyconnected is found argc must be 6 else we throw exception
        }
        else fullyconnected(argv[2],argv[3],argv[4],argv[5]);// returning resultant function 
    }
}