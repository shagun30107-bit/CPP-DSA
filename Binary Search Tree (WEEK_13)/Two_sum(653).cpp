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

 // Method-1 [ Brute approach ]
 // Traverse inorder - Store elements in an array uh get sorted array then apply 2 sum function on this to find
 // TC-O(N)+O(N)
 // SC-O(N)

 // Method-2 [ Optimal ]
 // BST iterator and add one more thing before()--> right node left 
 // check next+before whether greater or less than according to that move pointer
 // TC-O(N) & SC-O(H)*2

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse=true;
    //reverse=true->before
    //reverse=false->next

private: 
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(!reverse) root=root->left;
            else root=root->right;
        }  
    }
public:
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse=isreverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);  //next
        BSTIterator r(root,true);   //for before
        int i=l.next();
        int j=r.next(); //r.before
        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};