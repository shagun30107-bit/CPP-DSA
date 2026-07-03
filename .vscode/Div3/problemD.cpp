#include<bits/stdc++.h>
using namespace std;

string ans(vector<int>& a, vector<int>& b){
    int n= a.size();
    int l=-1;
    int r=-1;
    for(int i=1 ; i<=n ; i++){
        if((a[i-1] != b[i-1]) && l==-1) l=i;
        if((a[n-i] != b[n-i]) && r==-1) r=n-i+1;
    }
    
    if(l==-1 && r==-1) return "YES";

    for(int i=l ; i<=r ; i++){
        if(a[i-1] != b[i-1]) {
            if((i-l)%2 == 0) a[i-1]++;
            else a[i-1]--;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(a[i] != b[i]) return "NO";
    }
    return "YES";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0; i<n ; i++){
            cin >> b[i];
        }
        cout << ans(a,b) << endl;
    }
    return 0;
}