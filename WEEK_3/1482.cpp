#include<bits/stdc++.h>
using namespace std;
    vector<int> minimaxi(vector<int>& nums){
        int minii=nums[0];
        int maxii=nums[0];
        for(int i=1 ; i< nums.size(); i++){
            if(minii > nums[i]) {
                minii=nums[i];
            }
            else if (maxii<nums[i]){
                maxii=nums[i];
            }
        }
        return {minii,maxii};

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m*1LL*k*1LL;
        if (bloomDay.size() < val) return -1;
        int ans=INT_MAX;
        vector<int> rangee=minimaxi(bloomDay);
        int low=rangee[0], high=rangee[1];
        while(low<=high){
            int poss=0;
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0 ; i< bloomDay.size() ; i++){
                if(bloomDay[i]<=mid) cnt++;
                else {
                    poss+=cnt/k;
                    cnt=0;
                }
            }
            poss+=cnt/k;
            if (poss>=m) {
                high=mid-1;
                ans=min(ans,mid);
            }
            else low=mid+1;
        }
        return ans;
    }