#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int close=INT_MAX;
        for(int i=0 ; i<nums.size()-2 ; i++){
            int low=i+1 , high=nums.size()-1;
            while(low<high){
                int sumo=nums[low]+nums[high]+nums[i];
                if(sumo > target){
                    high--;
                    if(abs(target-sumo) < close) {
                        ans=sumo;
                        close=abs(target-sumo);
                    }
                }
                else{
                    low++;
                    if(abs(target-sumo) < close) {
                        ans=sumo;
                        close=abs(target-sumo); 
                    } 
                }     
            }
        } 
        return ans;    
    }
};
