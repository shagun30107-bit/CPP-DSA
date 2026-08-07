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
// U have 3 things in this-> brute, better and optimal 
// Ex- Longest subarray length whose sum <=k
// Brute-> Find the length of the all the subarray and the compare;
int length_brute(vector<int> arr , int k){
    int length=0;
    for(int i=0 ; i< arr.size() ; i++){
        int sum=0;
        for(int j=i ; j< arr.size() ; j++){
            sum+=arr[j];
            if(sum <= k) length=max(length,j-i+1);
            else break;
        }
    }
    return length;
}

// better solution--> two pointer approach
// TC-O(2N) --> One N for expand and other one is for shrink & SC-O(1)
int length_better(vector<int> arr , int k){
    int maxlen=0;
    int l=0,r=0;
    int sum=0;
    while(r < arr.size()){
        sum+=arr[r];
        while(sum>k){
            sum-=arr[l];
            l++;
        }
        if(sum<=k){
            maxlen=max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}

// Optimal solution same as better
// TC-O(N)--> but if u find to subarray not length then go with better solution
int length_optimal(vector<int> arr , int k){
    int maxlen=0;
    int l=0,r=0;
    int sum=0;
    while(r < arr.size()){
        sum+=arr[r];
        if(sum>k){
            sum-=arr[l];
            l++;
        }
        if(sum<=k){
            maxlen=max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> arr={-1,2,3,3,4,5,-1};
    cout << length_better(arr,5);
    return 0;
}