#include<bits/stdc++.h>
using namespace std;
//same as binary subarray with sum k 
//covert all odds into 1 and even into 0
class Solution {
public:

    int atmost(vector<int>& nums, int goal) {
        int l=0,r=0,count=0,sum=0;
        if(goal<0) return count;
        while(r< nums.size()){
            sum+=(nums[r]%2);
            while(sum>goal){
                sum-=(nums[l]%2);
                l++;
            }
            if(sum<=goal){
                count+=(r-l+1); //all the subarrays
            }
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};