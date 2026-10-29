#include<bits/stdc++.h>
using namespace std;

// Topological Sorting_ Kahn's Algorithm (BFS)
// BFS i.e, need a QUEUE...
// Inderee:- No. of incoming edges to a node 

// If some node does not have incoming edge it place starting of the list(ams)

//Step= Insert all nodes with indegree zero in the queue (FIFO)
// Take them out of queue 

class solution {
    public:
    vector<int> topo(int V, vector<int> adj[]){
        int indegree[V]={0};
        for(int i=0 ; i<V ; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0 ; i<V; i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int> t_sort;
        // O(V+E)
        while(!q.empty()){
            int node= q.front();
            q.pop();
            t_sort.push_back(node);
            // Now node is in ur topo sort
            // so please remove it from the indegree

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return t_sort;
    }
};