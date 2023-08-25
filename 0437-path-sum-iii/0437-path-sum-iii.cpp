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
    int count = 0;
    void solve(TreeNode* root, long target){
        if(!root) return;
        if(root->val == target) count++;
        solve(root->left, target-root->val);
        solve(root->right, target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        solve(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};