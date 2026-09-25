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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //Multiple possibilites:(
        //Find where it can insert
        if(root==NULL) return new TreeNode(val);
        TreeNode *curr=root;
        while(1){
            if(curr->val <= val ){ //i.e, we have to move right 
                if(curr->right != NULL) curr=curr->right;
                else{
                    //it is NULL insert there
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != NULL) curr=curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }      
            }
        }
        return root;
    }
};