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
    void traverse(TreeNode* root, vector<int>& arr){
        if(root==NULL) return;
        arr.push_back(root->val);
        traverse(root->left,arr);
        traverse(root->right,arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        traverse(root,arr);
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};