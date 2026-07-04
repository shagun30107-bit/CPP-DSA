#include<bits/stdc++.h>
using namespace std ;
    int upperbound(vector<int> num,int x){
        int low=0,high=num.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(num[mid]>x) high=mid-1;
            else low=mid+1;
        }
        return low; // number of elements <= x
    }
    int countofSmallerorEqual(vector<vector<int>> matrix , int x){
        int count=0;
        for(int i=0 ; i<matrix.size() ; i++){
            count+=upperbound(matrix[i],x);
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<=high){
            int mid=(low+high)/2;
            int count=countofSmallerorEqual(matrix,mid);
            if(count < k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }