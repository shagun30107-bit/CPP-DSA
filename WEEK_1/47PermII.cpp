#include<bits/stdc++.h>
using namespace std;
    void preRec(vector<int> &num, int begin , set<vector<int>> &st){
        if(begin >= num.size()) {
            st.insert(num) ;
            return;
        }
        for(int i=begin ; i< num.size() ; i++){
            swap(num[begin],num[i]);
            preRec(num,begin+1,st);
            swap(num[begin],num[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> result;
        preRec(nums,0,st);
        for(auto it:st){
            result.push_back(it);
        }
        return result;
    }

int main(){
    return 0;
}