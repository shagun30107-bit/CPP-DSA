#include<bits/stdc++.h>
using namespace std;
 vector<int> searchRange(vector<int>& nums, int target) {
        //O(N)(do it again)
        int n = nums.size();
        vector<int> temp={-1,-1};
        int v=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==target && v==0){
                temp[0]=i;
                temp[1]=i;
                v++;
            }
            else if(nums[i] == target){
                temp[1]=i;
            }
        }
        return temp;
    }
int main(){
    return 0;
}
