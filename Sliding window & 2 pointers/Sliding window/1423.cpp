#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //TC-O(K^2)
        int n=cardPoints.size();
        int l=n-1,r=k-1;
        int maxsum=0;
        for(int i=0 ; i<k ; i++){
            maxsum+=cardPoints[i];
        }
        r--;
        while(r>-2){
            int sum=0;
            for(int i=0; i<=r ; i++) sum+=cardPoints[i];
            for(int i=l ; i<n ; i++) sum+=cardPoints[i];
            l--;
            r--;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }

    //TC-O(2*K)
    int maxScore2(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0;
        int maxsum=0;
        for(int i=0; i< k ; i++){
            lsum+=cardPoints[i];
        }
        maxsum=lsum;
        int rindex=n-1;
        for(int i=k-1 ; i>=0 ; i--){
            lsum-=cardPoints[i] ;
            rsum+=cardPoints[rindex];
            rindex--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};

