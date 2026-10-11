#include<bits/stdc++.h>
using namespace std;

// SC=O(N)+O(N) for queue and visited array
// TC=O(N)+O(2E) for traversing all nodes and edges

class BFS{
    public:
    //Function to return BFS of given graph
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};