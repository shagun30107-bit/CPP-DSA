#include<bits/stdc++.h>
using namespace std;

// int hashh[10000000];
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }

//     // precompute
//     // int hash[13] = {0};
//     for( int i=0; i<n; i++){
//         hashh[arr[i]] += 1;

//     }
//     int q;
//     cin >> q;
//     while(q--){
//         int k;
//         cin >> k;
//         // fetch
//         cout << hashh[k] << endl;
//     }
//     return 0;
// }


// CHARACTER HASHING
// int main(){
//     string s;
//     cin >> s;

//     //precompute
//     int hash[26]={0};
//     for(int i=0 ; i<s.size() ;i++) {
//         hash[s[i] - 'a']++;
//     }
//     int n;
//     cin >> n;
//     while(n--){
//         char k;
//         cin >> k;
//         cout << hash[k-'a'] << endl;
//     }
//     return 0;
// }

// Number Hashing(>10^7)
int main(){
    int n;
    cin >> n;
    int arr[n];
    map<int,int> mpp;
    for(int i=0; i<n ; i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    // iterate in the map
    // for(auto it : mpp){
    //     cout << it.first << "->" << it.second << endl;
    // }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;

    }

    return 0;
}

//storing & fetching bothe talkes O(logn)