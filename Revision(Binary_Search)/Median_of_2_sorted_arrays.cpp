#include<bits/stdc++.h>
using namespace std;

//Approach-
//Firstly decide how many of arr1 and arr2 are in left or right side
//then cross compare it
//Assign variable l1= left side arr1 last element(max element)
// l2= left side arr2 last element(max ele)
// r1= right side arr1 first element(smallest ele)
// r2= right side arr2 first element(smallest one)

//if size of merge array is even->
// Then, median = ( max(l1,l2) + min(r1,r2) )/2

//else->
// median=max(l1,l2) 3-2 
//or median=max(r1,r2) 2-3
//Now to figure out how many elements of arr1 in the left side
//We'll do binary search on shorter array
// In the left side it's possible i select 0 elements or the all elements--
//[0,......,arr1.size()]
//if(l1>r1) high=mid-1
//if(l2>r1) low=mid+1


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0 , high=n1;
        int n=(n1+n2);
        int left=(n+1)/2;

        while(low<=high){
            int mid1= (low+high)/2;
            int mid2= left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1 < n1) r1=nums1[mid1];
            if(mid2 < n2) r2=nums2[mid2];
            if(mid1-1 >= 0) l1= nums1[mid1-1];
            if(mid2-1 >= 0) l2= nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high= mid1-1;
            else low=mid1+1;

        }
        return 0;
    }
};
