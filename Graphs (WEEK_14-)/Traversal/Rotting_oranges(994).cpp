#include<bits/stdc++.h>
using namespace std;

// TC=O(N*M)
// SC=O(N*M)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshO = 0;
        
        // Find all initial rotten oranges & count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); 
                } 
                else if (grid[i][j] == 1) {
                    freshO++;
                }
            }
        }
        
        if (freshO == 0) return 0;
        
        int minutes = 0;
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            bool rottedAny = false;
            
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nrow = r + delrow[d];
                    int ncol = c + delcol[d];
                    
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2; 
                        q.push({nrow, ncol});
                        freshO--;
                        rottedAny = true;
                    }
                }
            }
            
            if (rottedAny) minutes++;
        }
        
        if(!freshO) return minutes;
        else return -1;
    }
};