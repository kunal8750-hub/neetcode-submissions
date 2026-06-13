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
    bool issame(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL){
            return true;
        }
        if(a==NULL || b==NULL){
            return false;
        }
        if(a->val != b->val){
            return false;
        }
        if(!issame(a->left,b->left)){
            return false;
        }
        if(!issame(a->right,b->right)){
            return false;
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(issame(root,subRoot)){
            return true;
        }
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return left || right;
    }
};
