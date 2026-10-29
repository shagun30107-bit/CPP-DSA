#include<bits/stdc++.h>
using namespace std;

// Topological Sort 
// ONly applicable on Directed Acyclic graph
// Linear ordering of vertices such that ig there is an edge b/w u & v , u appears before v in their ordering

// By DFS

// -> 
// Write the adjaent node of the main nodr
class Topological{
private:
void dfs(int node ,int vis[], stack<int> st, vector<int> adj[] ){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it,vis,st,adj);   
    }
    st.push(node);
}
public:
    vector<int> sort(int V, vector<int> adj[]){
        int vis[V]={0};
        stack<int> st;
        for(int i=0 ; i< V ; i++){
            if(!vis[i]) {
                dfs(i,vis,st,adj);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
