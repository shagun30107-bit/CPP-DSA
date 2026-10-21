#include<bits/stdc++.h>
using namespace std;

// TC=O(N+E)
// SC=O(N)+O(N) for visited and pathvisited array

// We can use only one visited array and mark the node as 2 when we are done with it. If we encounter a node which is already marked as 1 then we have a cycle.
bool dfs(int src, vector<int> adj[], vector<int>&vis, vector<int>& pathvis){
    vis[src] = 1;
    pathvis[src] = 1;
    for(auto it: adj[src]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis)) return true;
        }
        else if(pathvis[it]) return true;
    }
    pathvis[src] = 0;
    return false;
}


bool iscycle(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    vector<int> pathvis(V,0);
    for(int i=1; i<=V ; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis)) return true;
        }
    }
    return false;
}