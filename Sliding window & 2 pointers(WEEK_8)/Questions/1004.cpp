#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     // TC=O(N^2)
     // Find all the subarrays & find largest subarray with atmost k zeroes
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        for(int i=0; i< nums.size(); i++){
            int zeroes=0;
            for(int j=i; j< nums.size() ; j++){
                if (nums[j]==0) zeroes++;
                if(zeroes<=k){
                    len=max(len, j-i+1);
                }
                else break;
            }
        }
        return len;
    }

    // TC-O(N)
    int longestOnes2(vector<int>& nums, int k) {
        int len=0;
        int zeroes=0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r] == 0) zeroes++;
            if(zeroes<= k) len=max(len,r-l+1);
            else{
                if(nums[l]==0) zeroes--;
                l++;
            }
            r++;
        }
        return len;
    }
};