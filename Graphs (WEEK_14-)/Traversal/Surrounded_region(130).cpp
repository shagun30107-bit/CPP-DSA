#include<bits/stdc++.h>
using namespace std;

// TC= O(n*m) + O(N+M) SC=O(n*m)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        // O(N+M) for storing all the boarder 'O'
        for(int i=0; i<n; i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        for(int i=0; i<m; i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[n-1][i]=='O') q.push({n-1,i});
        }

        // at this point i store all the boarder 'O'

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
            for(int i=0; i<4 ; i++){
                int nrow= row+ delrow[i];
                int ncol= col+ delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i=1; i<n-1 ; i++){
            for(int j=1; j<m-1 ; j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};