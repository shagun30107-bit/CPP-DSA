#include<bits/stdc++.h>
using namespace std;

long long value(long long n , long long x , long long y){
        long long v= n/(x+y);
        if (n%(x+y) == 0) return v;
        else return v+1;
}
long long ans(long long n, long long x , long long y, long long z){

    // if it's use the AI
    long long temp1=value(n,x,y);
    long long temp2;
    long long remaining =n- x*z;
    if(remaining <= 0) temp2=z;
    else temp2= z + value(remaining, x, 10*y);

    return min(temp1,temp2);
}
int main(){
    long t;
    cin >> t;
    while(t--){
        long long n, x, y, z;
        cin >> n >> x >> y >> z;
        cout << ans(n,x,y,z) << endl;
    }

    return 0;
}