#include<bits/stdc++.h>
using namespace std;

// TC=O(N*M)+O(4*N*M) for traversing all nodes and edges
// SC=O(N*M)+O(N*M) for queue and visited array
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); //rows
        int m=grid[0].size(); //column
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
private:
    void bfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int n=grid.size(); //rows
        int m=grid[0].size(); //column
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            // traverse in the neighbour and mark them
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};
            for(int i=0 ; i<4 ;i++){
                int nrow=row1+delrow[i];
                int ncol=col1+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
};