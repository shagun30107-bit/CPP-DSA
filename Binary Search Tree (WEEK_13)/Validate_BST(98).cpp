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
    void inorder(TreeNode* root, TreeNode*& prev, bool& isValid) {
        // Base case 
        if (root == nullptr || !isValid) return;

        // left
        inorder(root->left, prev, isValid);

        // If 'prev' exists, its value must be strictly less than the current node's value
        if (prev != nullptr && prev->val >= root->val) {
            isValid = false;
            return; 
        }
        
        // Move 'prev' pointer
        prev = root;

        // Right
        inorder(root->right, prev, isValid);
    }

    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        TreeNode* prev = nullptr; 
        
        inorder(root, prev, isValid);
        return isValid;
    }
};