#include<bits/stdc++.h>
using namespace std;
    int maxi(vector<int>& piles){
        int maxii=piles[0];
        for(int i=1; i<piles.size() ; i++){
            if(piles[i]>maxii) {
                maxii=piles[i];
            }
        }
        return maxii;
    }
    double totalhrs(vector<int>& arr, int h){
        double total=0;
        for(int i=0; i< arr.size() ; i++){
            total+=ceil(double(arr[i])/double(h));
        }
        return total;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=maxi(piles);
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(totalhrs(piles,mid) > h) low=mid+1;
            else{
                ans=min(ans,mid);
                high=mid-1;
            }
        }
        return ans;
    }