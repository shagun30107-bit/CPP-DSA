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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        bool lefttoright=true;
        q.push(root);
        while(!q.empty()){
            int m=q.size();
            vector<int> level;
            for(int i=0; i<m; i++){
                TreeNode *node= q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            if(!lefttoright) reverse(level.begin(),level.end());
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans;
    }
};