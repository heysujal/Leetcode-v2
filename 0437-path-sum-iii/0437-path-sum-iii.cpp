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
    int solve(TreeNode* root, long sum){
        if(!root)
            return 0;
        long left = solve(root->left,sum-root->val);
        long right = solve(root->right,sum-root->val);
        return (sum == root->val) + left + right;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        return solve(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};