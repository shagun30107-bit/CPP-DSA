#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q; // initially i'll store all 0's here
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(mat[i][j]==0) q.push({i,j});
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            int initialv =  mat[r][c];
            q.pop();
            vis[r][c]=1;
            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};
            for(int i=0; i<4 ; i++){
                int nrow= r + delrow[i];
                int ncol= c + delcol[i];
                if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m &&
                    mat[nrow][ncol] != 0 && !vis[nrow][ncol]){
                    //if value updates then push into the queue 
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    mat[nrow][ncol] = 1 + initialv;
                }
            }
        }

        return mat;
    }
};