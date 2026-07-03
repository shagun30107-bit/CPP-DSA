#include<bits/stdc++.h>
using namespace std ;
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int mini=INT_MAX;
        if(nums[low] < nums[high]) return nums[low];
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low] == nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                mini=min(mini,nums[mid]);
                continue;
            }
            if(nums[mid] <= nums[high]){
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
            else if (nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
        }
        return mini;
    }