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
    void kin(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        kin(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        kin(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // First method
        // Traverse , contain the element in a container then sort it..
        // Second method Traverse in Inorder (It's automatically store element in incending manner)
        int cnt = 0;        
        int ans;
        kin(root, cnt, ans, k);
        return ans;
    }
};