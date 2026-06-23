#include<bits/stdc++.h>
using namespace std;
    int sum(vector<int> arr){
        int sumi=0;
        for(int i=0; i<arr.size(); i++){
            sumi+=arr[i];
        }
        return sumi;
    }
    int max(vector<int>& arr){
        int maxi=arr[0];
        for(int i=1; i<arr.size() ; i++){
            if(arr[i]> maxi) {
                maxi=arr[i];
            }
        }
        return maxi;
    }

    int dayR(vector<int>& nums, int cap){
        int day=1;
        int load=0;
        for(int i=0; i<nums.size() ; i++){
            if(load+nums[i] > cap){
                day++;
                load=nums[i];
            }
            else load+=nums[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=max(weights),high=sum(weights);
        
        while(low<=high){
            int mid=(low+high)/2;
            if(dayR(weights,mid) > days){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }