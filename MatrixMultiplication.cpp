#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>

using namespace std;
/*
to perform the matrix multiplication and display the same using STL algorithm
Take the two matrices as vector and pass them to the matrix multiplication function
The matrices are passed to the function only if the number of column of matrix 1 and the number of rows of matrix 2 are equal
after multiplying and storing it to the resultant matrix and displaying them using display_matrix function
*/
void display_matrix(const vector<vector<int>> & matrix)
{
    for(const vector<int> & r: matrix)
    {
        for(int element:r)
            cout<<element<<" ";
        cout<<endl;
    }
    cout<<endl;
}


void Matrix_multiplication(const vector<int>& A, const vector<int>& B, int r1,int c1,int c2)
{
    vector<vector<int>> C(r1, vector<int>(c2,0));

    int i,j,k;

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                C[i][j] += A[i*c1 +k]*B[k*c2 + j];
            }
        }
    }

    display_matrix(C);
}



int main()
{
    int r1,r2,c1,c2;

    int i,j;

    cout<<"Enter the number of rows and columns of the matrix 1: ";
    cin>>r1>>c1;

    cout<<"\nEnter the number of rows and columns of the matrix 2: ";
    cin>>r2>>c2;

    vector<int> A(r1*c1);
    vector<int> B(r2*c2);

     if(c1 != r2)
     {
        cout<<"\nMatrix Multiplication is not possible."<<endl;
        return 1;
     }

     //Get the matrix values
     cout<<"Enter the values of the matrix A: "<<endl;
     for(i = 0;i<r1;i++)
     {
         for(j = 0;j<c1;j++)
            cin>>A[i*c1+j];
     }

     cout<<"Enter the values of the matrix B: "<<endl;
     for(i = 0;i<r2;i++)
     {
         for(j = 0;j<c2;j++)
            cin>>B[i * c2 + j];
     }



     //display the matrices
     cout<<"Matrix A:"<<endl;
     for(i=0;i<r1;i++)
     {
         for(j = 0;j<c1;j++)
         {
             cout<<A[i * c1 + j]<<" ";
         }
         cout<<endl;
     }

     cout<<"Matrix B:"<<endl;
     for(i=0;i<r2;i++)
     {
         for(j = 0;j<c2;j++)
         {
             cout<<B[i * c2 + j]<<" ";
         }
         cout<<endl;
     }

     cout<<"Resultant Matrix: "<<endl;
     Matrix_multiplication(A,B,r1,c1,c2);

     return 0;
}
