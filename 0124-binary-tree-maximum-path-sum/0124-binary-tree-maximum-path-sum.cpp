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
    // keeps a potential answer of curve using self
    // it return max(left, right) + self to the upper node 
    int ans = INT_MIN;
    int solve(TreeNode*root){
        if(!root){
            return 0;
        }
        auto left = solve(root->left);
        auto right = solve(root->right);
        auto self = root->val;
        auto curved = root->val + left + right;
        auto straight = root->val + max(left, right);
        ans = max(ans, max(self, max(straight, curved)));
        return straight;
    }
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return ans;
    }
};