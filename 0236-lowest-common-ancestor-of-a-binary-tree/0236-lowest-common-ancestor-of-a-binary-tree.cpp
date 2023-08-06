/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// left and right
// if root->val matches either p or q (non-null) then return root;
// try leftLCA and rightLCA if they
// whichever is non null return that
// else return null

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val == p->val or root->val == q->val)
            return root;
        TreeNode* leftLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);

        if(leftLCA and rightLCA)
            return root;
        if(leftLCA)
            return leftLCA;
        if(rightLCA)
            return rightLCA;
        return NULL;
        
    }
};