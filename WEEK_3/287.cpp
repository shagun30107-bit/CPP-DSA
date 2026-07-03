#include<bits/stdc++.h>
using namespace std; 
 
 int findDuplicate(vector<int>& nums) {
        //TC=O(N) SC=O(N)
        unordered_set<int> s;
        for(int num:nums){
            if(s.find(num) != s.end()) return num;
            s.insert(num);
        }
        return -1;
    }