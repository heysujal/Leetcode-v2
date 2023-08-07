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
    bool isMirror(TreeNode* p, TreeNode* q){
        if(!p and !q)
            return true;
        if(!p or !q)
            return false;
        bool left = isMirror(p->left,q->right);
        bool right = isMirror(p->right,q->left);
        return p->val == q->val and left and right;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root,root);
    }
};