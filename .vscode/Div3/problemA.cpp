#include<bits/stdc++.h>
using namespace std;

string ans(float x, float y){
    int t1=x/y;
    double t2=x/y;
    if(t1==t2) return "YES";
    return "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y ;
        cout << ans(x,y) << endl;
    }
}