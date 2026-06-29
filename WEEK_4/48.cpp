#include<bits/stdc++.h>
using namespace std ;
 
    void reverse(vector<int>& nums){
        for(int i=0 ; i<nums.size()/2 ; i++){
            swap(nums[i], nums[nums.size()-i-1]);
        }
    }
    void transpose(vector<vector<int>>& matrix){
         int n=matrix.size();
         for(int i=0 ; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
         }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        transpose(matrix);
        for(int i=0; i<n ; i++){
            reverse(matrix[i]);
        }
    }