#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //TC=O(N**2)
        //Max length subarray with atmost 2 types of numbers
        int len=0;
        for(int i=0; i<fruits.size() ; i++){
            set<int> st;
            for(int j=i; j<fruits.size() ; j++){
                st.insert(fruits[j]);
                if(st.size() <= 2) len=max(len,j-i+1);
                else break;
            }
        }
        return len;
    }

    //TC-O(2*N)
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,len=0;
        map<int,int> mpp;
        while(r< fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }

    //TC-O(N)
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,len=0;
        map<int,int> mpp;
        while(r< fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};