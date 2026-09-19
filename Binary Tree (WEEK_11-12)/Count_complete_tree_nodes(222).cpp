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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int leftheight(TreeNode* node){
        if(node==NULL) return 0;
        int lh=0;
        while(node){
            node=node->left;
            lh++;
        }
        return lh;
    }
    int rightheight(TreeNode* node){
        if(node==NULL) return 0;
        int rh=0;
        while(node){
            node=node->right;
            rh++;
        }
        return rh;
    }
};