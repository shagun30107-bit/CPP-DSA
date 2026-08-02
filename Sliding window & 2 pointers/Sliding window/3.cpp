#include<bits/stdc++.h>
using namespace std;

// 1st Method
// TC-O(N^2) & SC-O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        for(int i=0 ; i< s.size() ; i++){
            int hash[256]={0};
            for(int j=i ; j< s.size() ; j++){
                if(hash[s[j]] == 1) break;
                len=max(len,j-i+1);
                hash[s[j]]=1;
            }
        }
        return len;
    }

    // T.C=O(N) & SC=O(256)
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int l=0,r=0;
        int len=0;
        while(r< s.size()){
            if(hash[s[r]]!= -1) {
                // In the map
                if(hash[s[r]] >= l) l=hash[s[r]]+1;
            }
            len=max(len,r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return len;
    }
};