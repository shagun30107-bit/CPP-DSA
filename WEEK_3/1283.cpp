#include<bits/stdc++.h>
using namespace std;
    int maxi(vector<int>& nums){
        int maxii=nums[0];
        for(int i=1 ; i< nums.size(); i++){
            if (maxii<nums[i]){
                maxii=nums[i];
            }
        }
        return maxii;
    }

    int divisor(vector<int>& nums,int temp){
        int sumi=0;
        for(int i=0 ; i< nums.size() ; i++){
            sumi+=ceil(double(nums[i])/(double)(temp));
        }
        return sumi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1; //maximum sum is length of array possible !!
        int low=1, high=maxi(nums);
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(divisor(nums,mid)<=threshold){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }