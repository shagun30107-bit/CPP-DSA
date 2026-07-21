#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach- 
    // If an element at (i,j) is 0:
    // Mark matrix[i][0]=0 (row marker)
    // Mark matrix[0][j]=0 (column marker)
    // We handle first row and first column using extra variables (count0 for row 0 and matrix[0][0] for col0) 
    // Traverse the matrix again(excluding first row and first column check for col and row if(matrix[i][0]==0 or matix[0][j]==0) then, set matrix[i][j]=0)

    // Finally handle the first col. (using matrix[0][0]) & first row using count0 
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size(); //rows
        int m= matrix[0].size(); //columns
        int count0=1;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                if(matrix[i][j] == 0){
                    //mark jth col
                    matrix[0][j]=0;
                    if(i!=0){
                        //mark ith row
                        matrix[i][0]=0;
                    }
                    else count0=0;
                }
            }
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i =0; i<n;i++){
                matrix[i][0]=0;
            }
        }
        if(count0 == 0){
            for(int j =0; j<m;j++){
                matrix[0][j]=0;
            }
        }
    }
};