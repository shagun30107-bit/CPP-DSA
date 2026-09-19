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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return BT(preorder, 0, preorder.size() - 1,
                  inorder, 0, inorder.size() - 1, inMap);
    }


    TreeNode* BT(vector<int>& preorder, int prestart, int preend,
                 vector<int>& inorder, int instart, int inend,
                 map<int, int>& inMap) {

        // Base case
        if (prestart > preend || instart > inend) {
            return NULL;
        }

        // First element of preorder is root
        TreeNode* root = new TreeNode(preorder[prestart]);

        // Find root position in inorder
        int inroot = inMap[root->val];

        // Number of nodes in left subtree
        int numsleft = inroot - instart;

        // Build left subtree
        root->left = BT(preorder,
                        prestart + 1,
                        prestart + numsleft,
                        inorder,
                        instart,
                        inroot - 1,
                        inMap);

        // Build right subtree
        root->right = BT(preorder,
                         prestart + numsleft + 1,
                         preend,
                         inorder,
                         inroot + 1,
                         inend,
                         inMap);

        return root;
    }
};