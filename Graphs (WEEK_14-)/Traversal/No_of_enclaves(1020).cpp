#include<bits/stdc++.h>
using namespace std;

// TC=O(N*M) + O(N+M)
// SC=O(N*M)+O(N*M) for queue and visited array
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        // Traverse on the boundaries make it visited
        for(int j=0; j<m ; j++){
            if(!vis[0][j] && grid[0][j] ) bfs(grid,0,j,vis);
            if(!vis[n-1][j] && grid[n-1][j] ) bfs(grid,n-1,j,vis);
        }

        for(int i=0; i<n ; i++){
            if(!vis[i][0] && grid[i][0]) bfs(grid,i,0,vis);
            if(!vis[i][m-1] && grid[i][m-1]) bfs(grid,i,m-1,vis);
        }

        // if it's not visited i.e, not joint with the cell of boundary or with the boundary
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]) cnt++;
            }
        }
        return cnt;
    }

private :
void bfs(vector<vector<int>>& grid,int row , int col,vector<vector<int>>& vis){
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        for(int i=0 ; i<4 ; i++){
            int nrow=r+ delrow[i];
            int ncol=c+ delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
        }
    }
}
};