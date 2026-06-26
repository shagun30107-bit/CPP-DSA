#include<bits/stdc++.h>
using namespace std;
    int powerhalf(int k){
        int low=0,high=k/2;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid == k) return mid;
            else if(mid*mid > k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    bool judgeSquareSum(int c) {
        int low=0,high=powerhalf(c);
        while(low<=high){
            long long sqr = (long long)low * low + (long long)high * high;
            if(sqr == c) return true;
            else if(sqr > c) high--;
            else low++;
        }
        return false;
    }