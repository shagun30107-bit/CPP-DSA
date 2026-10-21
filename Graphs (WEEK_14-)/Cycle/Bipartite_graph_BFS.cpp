#include<bits/stdc++.h>
using namespace std;

class solution{

private:
    //TC= O(N)+O(2E)
    //SC=O(N)+O(N)
    bool check(int V, int start, vector<int> adj[], int color[]){
        queue<int> q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                // if it is not color 
                if(color[it] == -1) {
                    // color[it] = !color[node];
                    if(color[node]==0) color[it]= 1;
                    else color[it] = 0;
                    q.push(it);
                }
                //if it is colored
                else if(color[node]==color[it]) return false; 
            }
        }
        return true;
    }

public :
    //TC=O(2N)
    //SC=O(N)
    bool isBipartite(int V, vector<int>adj[]){
        int color[V];
        for(int i=0; i<V ; i++){
            color[i]=-1;
        }
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(!check(V,i,adj,color)) return false;
            }
        }
        return true;
    }
};