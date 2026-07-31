#include<bits/stdc++.h>
using namespace std;

// When we use the two pointer/sliding window method-->
//1) Constant Window

// Suppose u have to find the maximum sum of k consecutive nmber in an array
// arr={-1,2,3,3,4,5,-1} and k=4
// take l=0 and r=k-1;
// u constantly move your window in this 
int maxsum(vector<int> arr,int k){
    int l=0,r=k-1;
    int maxsum=0;
    for(int i=l; i<=r ; i++){
        maxsum+=arr[i];
    }
    int sum=maxsum;
    while(r< arr.size()-1){
        maxsum=maxsum - arr[l] ;// move this window to the right
        l++;
        r++;
        maxsum=maxsum + arr[r] ;
        sum=max(sum,maxsum);
    }
    return sum;
}


//2) Longest subarray/substring where <condition>

int main(){
    vector<int> arr={-1,2,3,3,4,5,-1};
    cout << maxsum(arr,4);
    return 0;
}