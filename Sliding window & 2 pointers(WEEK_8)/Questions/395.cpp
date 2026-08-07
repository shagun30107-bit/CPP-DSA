#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int len=0;
        for(int i=0 ; i< s.size() ; i++){
            int hash[256]={0};
            for(int j=i ; j< s.size() ; j++){
                hash[s[j]]++;
                if(hash[s[j]] >= k) len=max(len,j-i+1);
            }
        }
        return len;
    }
};