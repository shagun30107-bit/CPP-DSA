#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC=O(N**2)
    int characterReplacement(string s, int k) {
        int maxof=0,len=0;
        for(int i=0; i< s.size() ; i++){
            int hash[26]={0};
            for(int j=i; j< s.size(); j++){
                hash[s[j]-'A']++;
                maxof= max(maxof, hash[s[j]-'A']);
                int changes= (j-i+1) - maxof;
                if(changes <= k){
                    len=max(len, j-i+1);
                }
                else break;
            }
        }
        return len;
    }

    //TC-O(2*N*26)
    int characterReplacement2(string s, int k) {
        int l=0,r=0,len=0,maxof=0;
        int hash[26]={0};
        while(r < s.size()){
            hash[s[r]-'A']++;
            maxof= max(maxof, hash[s[r]-'A']);
            while((r-l+1)-maxof > k){
                hash[s[l]-'A']--;
                maxof=0;
                for(int i=0 ; i<26 ; i++){
                    maxof=max(maxof, hash[i]);
                }
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }

    //TC-O(N)
    // for loop only reduce my maxof which i don't need !!
    int characterReplacement2(string s, int k) {
        int l=0,r=0,len=0,maxof=0;
        int hash[26]={0};
        while(r < s.size()){
            hash[s[r]-'A']++;
            maxof= max(maxof, hash[s[r]-'A']);
            if((r-l+1)-maxof > k){
                hash[s[l]-'A']--;
                maxof=0;
                l++;
            }
            else len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};