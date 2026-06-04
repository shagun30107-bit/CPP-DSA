#include<bits/stdc++.h>
using namespace std;
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(el==nums[i]){
                cnt++;
            }
            else cnt--;
        }
        int ct=0;
        for(int i=0;i<n; i++){
            if(nums[i]==el) ct++;
        }
        if (ct > n/2) return el;
        return -1;
    }
int main(){
    return 0;
}