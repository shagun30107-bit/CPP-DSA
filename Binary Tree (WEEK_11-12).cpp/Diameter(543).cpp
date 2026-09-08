/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        calculateHeight(root, dia);
        return dia;
    }

private:
    // Pass 'maxi' by reference (int& maxi) so changes persist across recursive calls
    int calculateHeight(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;
        
        int lh = calculateHeight(node->left, maxi);
        int rh = calculateHeight(node->right, maxi);
        
        // The diameter passing through this node is the sum of left and right heights
        maxi = max(maxi, lh + rh);
        
        // Return the height of the current subtree
        return 1 + max(lh, rh);
    }
};