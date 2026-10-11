#include<bits/stdc++.h>
using namespace std;

int main(){
    // Graph Representation
    // 1. Adjacency Matrix  
    int n,m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    // 2. Adjacency List
    vector<int> ad[n+1];   
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    return 0;
}