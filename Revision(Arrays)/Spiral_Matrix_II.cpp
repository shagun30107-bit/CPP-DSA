#include<bits/stdc++.h>
using namespace std;

//TC=O(N*N) & SC-O(N*N)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int cnt=1;
        while(left<=right && top<=bottom){
            //right
            for(int i=left ; i<=right ; i++){
                matrix[top][i] = cnt;
                cnt++;
            }
            top++;
            //bottom
            for(int i=top ; i<=bottom ; i++){
                matrix[i][right]=cnt;
                cnt++;
            }
            right--;
            //left
            if(top<=bottom){
                for(int i=right; i>=left ;i--){
                    matrix[bottom][i]=cnt;
                    cnt++;
                }
                bottom--;
            }
            //top
            if(left<=right){
                for(int i=bottom ; i>=top ; i--){
                    matrix[i][left]=cnt;
                    cnt++;
                }
                left++;
            }
        }
        return matrix;
    }
};