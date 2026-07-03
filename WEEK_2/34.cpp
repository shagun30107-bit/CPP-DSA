#include<bits/stdc++.h>
using namespace std;

 int lower(vector<int>& nums, int target){
        int n=nums.size();
        int lb=-1;
        int low=0 , high= n-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(nums[mid] == target){
                lb=mid;
                //left
                high=mid-1;
            }
            else if(nums[mid] < target) low=mid+1;
            else high=mid-1;
        }
        return lb;
    }

    int upper(vector<int>& nums, int target){
        int n=nums.size();
        int ub=-1;
        int low=0 , high= n-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(nums[mid] == target){
                ub=mid;
                //right
                low=mid+1;
            }
            else if(nums[mid] < target) low=mid+1;
            else high=mid-1;          
        }
        return ub;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower(nums,target),upper(nums,target)};

    }

int main(){
    return 0;
}