#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //method-1
    //tc-O(N) & SC-O(N)
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        int n=nums.size();
        unordered_map<int,int> prefix;
        prefix[0]=1;
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];

            if(prefix.find(sum-k) != prefix.end()){
                count += prefix[sum-k];
            }
            prefix[sum]++;
        }
        return count;
    }

    //Method-2
    //to find this we have a mathematically apprach 
    //first find the how many subarray in which your sum<=goal 
    // then your answer willbe 
    // numSubarrayWithSum(nums,goal)-numSubarrayWithSum(nums,goal-1)
    // Simple mathematics
    // TC-O(2*2*N)
    int atmost(vector<int>& nums, int goal) {
        int l=0,r=0,count=0,sum=0;
        if(goal<0) return count;
        while(r< nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                count+=(r-l+1); //all the subarrays
            }
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)- atmost(nums,goal-1);
    }
};