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
    int max_val = 0;
    void helper(TreeNode* root, TreeNode* ancestor){
        if(!root) return;
        max_val = max(max_val, abs(root->val - ancestor->val));
        helper(root->left, ancestor);
        helper(root->right, ancestor);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        helper(root, root);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return max_val;
    }
};