#include<bits/stdc++.h>
using namespace std;

// TC=O(N*M)+O(4*N*M) for traversing all nodes and edges
// SC=O(N*M)+O(N*M) for queue and visited array

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(!vis[sr][sc] && image[sr][sc]!=color){
            bfs(image,sr,sc,vis,color);
        }
        return image;
    }
private:
    void bfs(vector<vector<int>>& image, int sr,int sc, vector<vector<int>>& vis, int color){
        int n=image.size();
        int m=image[0].size();
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[]={0,0,1,-1};
            int delcol[]={1,-1,0,0};
            for(int i=0; i<4; i++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldColor && !vis[nrow][ncol]){
                        image[nrow][ncol]=color;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
};