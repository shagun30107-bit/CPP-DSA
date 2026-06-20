#include<bits/stdc++.h>
using namespace std;
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int idx=-1;
        int low=0 ,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //check which is sorted
            if(arr[mid]==target) idx=mid;
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]) high=mid-1;
                else low = mid+1;
            }
            else{
                if(arr[mid]<= target && target <= arr[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return idx;
    }

int main(){
    return 0;
}