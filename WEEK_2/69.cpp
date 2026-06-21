#include<bits/stdc++.h>
using namespace std;
    int mySqrt(int x) {
        if(x==1) return 1;
        long long ans;
        long long low=0 , high=x/2;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long midsq=mid*mid;
            if( midsq == x) return mid;
            else if(midsq > x) high=mid-1;
            else low=mid+1;
        } 
        return high;
    }