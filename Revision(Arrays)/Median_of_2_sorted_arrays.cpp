#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double median(vector<int> arr){
        int n=arr.size();
        double med;
        if(n%2 != 0) med=arr[n/2];
        else med=(arr[(n/2)-1] + arr[n/2])/2.0;
        return med;
    }
    vector<int> Union(vector<int>arr1 , vector<int>arr2){
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        vector<int> ans;
        while(i<n && j<m){
            if(arr1[i] <= arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        if(i<n){
            while(i<n){
                ans.push_back(arr1[i]);
                i++;
            }
        }
        if(j<m){
            while(j<m){
                ans.push_back(arr2[j]);
                j++;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return(median(Union(nums1,nums2)));
    }
};

