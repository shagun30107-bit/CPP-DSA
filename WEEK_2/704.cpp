#include<bits/stdc++.h>
using namespace std;
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0 , high = n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid] == target) return mid;
            else if (arr[mid] < target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }

int main(){
    return 0;
}