#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //Brute solution--O(N**2)
        int ans=INT_MIN;
        int n=height.size();
        for(int i=0; i<n-1 ; i++){
            for(int j=i+1; j<n ; j++){
                int side=min(height[i], height[j]);
                int expect = (j-i)*side;
                if(expect>ans) ans=expect;
            }
        }
        return ans;
    }
// Optimal Solution-O(N)
    int maxArea1(vector<int>& height) {

        int i=0,j=height.size()-1;
        int ans=INT_MIN;
        while(i<j){
            ans= max(ans, (j-i)*(min(height[i],height[j])));

            if(height[i] < height[j]) i++;
            else{
                j--;
            }
        }
        return ans;
    }
};