#include<bits/stdc++.h>
using namespace std;

// Find out the alien order of characters in the alien language
//Example- {baa,abcd,abca,cab,cad}
//Output should be - bdac

//Approach- Take two two pairs and find which alphabet come first and make the Directed graph of this
//Then it's topo sort will be ur answer

// When the order is not possible - 1) abcd appear before the abc 2) Cyclic dependency abc,bad,adc
class solution{

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
    public:
    string findOrder(string dict[], int N, int K){
        // make graph
        vector<int>adj[K];
        for(int i=0; i<N-1;i++){
            string s1= dict[i];
            string s2= dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int ptr=0; ptr<len ; ptr++){
                if(s1[ptr] != s2[ptr]) {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        vector<int> topo_l = topo(K,adj);
        string ans="";
        for(auto it:topo_l){
            ans=ans+ char(it+'a');
        }
        return ans;
    }
};