int isBadVersion(int version){
    //defined in question 
}
#include<bits/stdc++.h>
using namespace std ;
    int firstBadVersion(int n) {
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isBadVersion(mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }