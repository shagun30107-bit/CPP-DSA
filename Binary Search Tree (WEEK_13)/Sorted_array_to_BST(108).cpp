#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Inorder to level order
        return con(nums,0,nums.size()-1);
    }

    TreeNode* con(vector<int> nums,int left,int right){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* node= new TreeNode(nums[mid]);

        node->left=con(nums,left,mid-1);
        node->right=con(nums,mid+1,right);
        return node;
    }
};