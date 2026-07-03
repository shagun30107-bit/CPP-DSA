 #include<bits/stdc++.h>
using namespace std ;
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int low=1,high=num/2;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long sqm=mid*mid;
            if(sqm == num) return true;
            else if(sqm<num) low=mid+1;
            else high=mid-1;
        }
        return false;
    }