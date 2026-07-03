#include<bits/stdc++.h>
using namespace std;


// int s_largest(vector<int> &arr,int n){
//     int largest=arr[0];
//     int s_largest=-1;
//     for(int i=1;i<n;i++){
//         if(arr[i]>largest) {
//             s_largest=largest;
//             largest=arr[i];
//         }
//         else if(arr[i] < largest && s_largest < arr[i]){
//             s_largest=arr[i];
//         }
//     }
//     return s_largest;
// }

// bool sort(vector<int> arr, int n){
//     for(int i=0; i<n-1 ; i++){
//         if (arr[i] > arr[i+1]){
//             return false;
//         }
//     }
//     return true;
// }

// int findKthLargest(vector<int>& nums, int k) {
//     set<int> st;
//     int n;
//     n=nums.size();
//     for (int i=0 ; i<n ; i++){
//         st.insert(nums[i]);
//     }
//     auto it = st.begin();
//     advance(it,n-k);
//     return *it;
// }

// int removeDuplicates(vector<int>& nums) {
//     //2 pointer approach
    
//     int n=nums.size();
//     int arr[n];
//     for(int i=0; i<n; i++){
//         arr[i]=nums[i];
//     }
//     int i=0;

//     for(int j=1;j<n;j++){
//         if(arr[j] != arr[i]){
//             arr[i+1]=arr[j];
//             i++;
//         }
//     }
//     return i+1 , arr[n];
// }

// int longestSubarrayWithSumK(vector<int> a, long long k){
//     map<long long, int> preSumMap;
//     long long sum =0;
//     int maxLen= 0;
//     for(int i=0; i< a.size() ; i++){
//         sum+=a[i];
//         if(sum==k){
//             maxLen= max(maxLen , i+1);
//         }
//         long long rem=sum-k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//           //i.e, rem present in presum
//           int len = i - preSumMap[rem];
//           maxLen = max(maxLen,len);
//         }
//         if(preSumMap.find(rem) != preSumMap.end()){
//             preSumMap[sum]=i;
//         }
//     }
        
//     return maxLen;
// }

// int optimalofAbove(vector<int> a, long long k){
//     int left=0,right=0;
//     long long sum=a[0];
//     int maxLen=0;
//     int n=a.size();
//     while(right<n){
//         while(left <= right && sum>k){
//             sum-=a[left];
//             left++;
//         }
//         if(sum==k){
//             maxLen = max(maxLen, right-left+1);
//         }
//         right++;
//         if(right <n) sum += a[right];
//     }
//     return maxLen;

// }
// int value(int x , int y){

// }

int main() {
    float x=32;
    float y=13;
    double z=x/y;
    cout << z;
}