#include<bits/stdc++.h>
using namespace std; 
    bool sorted(vector<int>& nums){
        // O(2NlogN + 2N)
        for(int i=0; i< nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    bool check(vector<int>& arr){
        for(int i=1 ; i< arr.size() ; i++){
            if(abs(arr[i] - arr[i - 1]) > 1) return false;
        }
        return true;
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr[0]==1 && sorted(arr) && check(arr)) return arr[arr.size()-1];
        sort(arr.begin(), arr.end());
        if(arr[0] != 1) {
            int i=0;
            arr[0]=1;
        }
        for(int i=1 ; i< arr.size() ; i++){
            if(abs(arr[i] - arr[i - 1]) > 1){
                arr[i]= 1 + arr[i-1];
            }
        }
        return arr[arr.size()-1];
    }