#include<bits/stdc++.h>
using namespace std ;
    bool searchin1D(vector<int>& arr,int x){
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x) return true;
            else if(arr[mid]>x) high=mid-1;
            else low=mid+1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][n-1] < target) {
                low=mid+1;
            }
            else{
                if(matrix[mid][0] <= target && matrix[mid][n-1]>= target) {
                    return searchin1D(matrix[mid],target);
                }
                high=mid-1;
            }
        }
        return false;
    }