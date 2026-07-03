#include<bits/stdc++.h>
using namespace std;
    void permuteRec(vector<int> &num , int begin , vector<vector<int>> &result){
        if(begin >= num.size()){
            result.push_back(num);
            return;
        }
        for(int i=begin; i< num.size() ; i++){
            swap(num[begin],num[i]);
            permuteRec(num,begin+1,result);
            //reset
            swap(num[begin],num[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRec(nums,0,result);
        return result;
       
    }
int main(){
    return 0;
}