#include<bits/stdc++.h>
using namespace std;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0 ; i<n-3 ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1 ; j<n-2 ; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l=j+1;
                int k=n-1;
                while(l<k){
                    long long sum_s=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum_s<target) l++;
                    else if (sum_s>target) k--;
                    else{
                        vector<int> temp={nums[i],nums[j],nums[l],nums[k]};
                        ans.push_back(temp);
                        l++;
                        k--;
                        while(l<k && nums[l] == nums[l-1]) l++;
                        while(l<k && nums[k] == nums[k+1]) k--;
                    }
                }
            }
        }
        return ans;
    }
int main(){
    return 0;
}