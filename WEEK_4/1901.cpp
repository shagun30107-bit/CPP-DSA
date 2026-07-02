 #include<bits/stdc++.h>
using namespace std ;
    int findmax(vector<vector<int>>& mat, int n, int m, int col){
        int maxValue=-1;
        int index=-1;
        for(int i=0 ; i<n ; i++){
            if(maxValue < mat[i][col]){
                maxValue=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=findmax(mat,n,m,mid);
            int left=-1;
            int right=-1;
            if(mid-1>=0) left=mat[row][mid-1];
            if(mid+1<m) right=mat[row][mid+1];
            if(mat[row][mid] > left && mat[row][mid] > right) return {row,mid};
            else if (mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }