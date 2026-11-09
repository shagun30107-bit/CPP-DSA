#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
public:
    // check whether it is topological sort it or not 
    // if it's topological sorts then it can finish else don't
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // By BFS
        vector<int> adj[V];
        for(auto it: prerequisites) adj[it[1]].push_back(it[0]);
        
        vector<int> indegree(V, 0);
        for(int i=0; i<V ; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        int size=0;
        for(int i=0; i<V; i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            size++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }

        }
        return size==V;
    }
};