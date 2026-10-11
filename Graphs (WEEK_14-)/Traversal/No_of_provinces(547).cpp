#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int city, vector<vector<int>>& isConnected , vector<bool> &visited){
        visited[city]=true;
        for(int i=0; i<isConnected.size(); i++){
            //i=neighbor
            // If there's a connection and the neighbor hasn't been visited yet
            if(isConnected[city][i]==1 && !visited[i]){
                dfs(i,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0; i<n ; i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);  // Visit all connected cities
            }
        }
        return count;
    }
};