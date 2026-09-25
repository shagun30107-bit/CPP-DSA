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

 //Method-1 [brute approach] 
 //Traverse then sort uh get it's inorder traversal then form BST
 //TC=O(N+NlogN+N)
 //SC=O(N)

 //Method-2(Inorder traverse and then check where last element is greater then the next element basically where it's voilated store that elemenent)
 //if uh get two violation then element are not adjacent
 //if only one violatuion uh get i.e, elements are adjacent
 //TTC=O(N) & SC=O(1)
class Solution {
private:
    TreeNode* first; // First voilation
    TreeNode* prev; //prev element
    TreeNode* middle; //adjacent element voilation
    TreeNode* last; //last voilation
private:
    void inorder(TreeNode* root){
        //left-root-right
        if(root==NULL) return;
        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            //if this is the first violation mark first, middle as
            if(first==NULL){
                first=prev;
                middle=root;
            }
            //if it's the second violation mark last as
            else last=root;
        }
        //mark this node as prev
        prev=root;
        inorder(root->right);

    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=prev=NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};