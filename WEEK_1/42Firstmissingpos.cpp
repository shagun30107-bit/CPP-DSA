#include<bits/stdc++.h>
using namespace std;
    //T.C->O(NlogN + N)
    //S.C->O(N)
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0 ; i< nums.size() ; i++){
            mpp[nums[i]]++;
        }
        for(int i=1 ; i<= nums.size() ; i++){
            if(mpp[i]==0) return i;
        }
        return nums.size() + 1;
    }

    // O(N) - O(1)
        int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            while(0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }

int main(){
    return 0;
}