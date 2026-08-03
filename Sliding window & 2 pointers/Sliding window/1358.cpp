#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Method-1-O(N**2)
    int numberOfSubstrings(string s) {
        int cnt=0;
        for(int i=0 ; i< s.size() ; i++){
            int hash[3]={0};
            for(int j=i ; j< s.size() ; j++){
                hash[s[j]-'a'] = 1;
                if(hash[0]+ hash[1] + hash[2] == 3) {
                    cnt=cnt+(s.size() - j);
                    break;
                }
            }
        }
        return cnt;
    }

    //Method-2(O(N))
    int numberOfSubstrings(string s) {
        int lastseen[3] = {-1, -1, -1};
        int cnt=0;
        for(int i=0 ; i< s.size() ;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
            }
        }
        return cnt;
    }
};