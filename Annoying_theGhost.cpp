#include<bits/stdc++.h>
using namespace std;

int max(vector<int>& arr){
    int maax=arr[0];
    for(int i=1 ; i< arr.size() ; i++){
        if(maax< arr[i]) maax=arr[i];
    }
    return maax;

}
int ans(vector<int>& a, vector<int>& b){
    if(max(a) > max(b)) return -1;

    
    vector<int> c=a;
    sort(c.begin(), c.end());
    int swapi=0;
    while(a!=c){
        for(int i=0 ; i<a.size()-1 ; i++){
            if(a[i] > a[i+1]) {
                swapi++;
                swap(a[i],a[i+1]);
            }
        }
    }  
    return swapi;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin >> b[i];
        }
        cout << ans(a,b) << endl;
    }
    return 0;
}

