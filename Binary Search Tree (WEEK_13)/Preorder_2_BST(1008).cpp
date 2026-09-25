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

 // 1st Method --> First element of nums is root, then move further if it is less than the node put it on the node->left else node->right 
 // TC=O(N*N)
 // 2nd Method --> Sort the array the sorted array give uh inorder traversal --Uh know hoe to convert it now...
 // TC=O(NlogN)+O(N)
 // 3rd Method --> TC=O(3N) ~ O(N)
 // SC-O(1) DEFINE UPPER BOUND AND TRAVERSE

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // preorder- root,left,right
        int i=0;
        return convert(preorder,i,INT_MAX);

    }
    TreeNode* convert(vector<int>& nums, int& i, int bound){
        if(i == nums.size() || nums[i] > bound) return NULL;
        TreeNode* root= new TreeNode(nums[i++]);
        root->left = convert(nums,i,root->val);
        root->right = convert(nums,i,bound);
        return root;
    }
};