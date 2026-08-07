#include<bits/stdc++.h>
using namespace std;
//HARD but not more ! 
// TC=O(2*2*N)
// SC=O(N)
class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int l=0,r=0,count=0;
        map<int,int> mpp;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size()<=k){
                count+=(r-l+1);
            }
            r++;
            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        if(k < 0) return 0;
        return atmost(nums,k) - atmost(nums,k-1);
    }
};