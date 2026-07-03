#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& a){
    int sume=0;
    for(int i=0 ; i< a.size() ; i++){
        sume+=a[i];
        for(int j=i+1 ; j<a.size() ; j++){
            if(a[i] < a[j]){
                a[j]=a[i];
                break;
            }
        }
    }   
    return sume;   
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<int> a(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        cout << ans(a) << endl;
    }
    return 0;
}