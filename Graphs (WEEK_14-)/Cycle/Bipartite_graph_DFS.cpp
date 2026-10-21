#include<bits/stdc++.h>
using namespace std;

class solution{
private:
    bool check(int start, int col, vector<int> adj[], int color[]){
        color[start]=col;
        for(auto it: adj[start]){
            if(color[it]==-1){
                if(!check(it,!col,adj,color)) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
public:
    bool isbipartite(int V, vector<int> adj[]){
        int color[V];
        for(int i=0; i<V; i++) color[i]=-1;
        for(int i=0; i<V;i++){
            if(color[i]==-1) {
                if(!check(i,0,adj,color)) return false;
            }
        }
        return true;
    }
};
