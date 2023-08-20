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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int straightPath = max(root->val, root->val + max(left,right));
        int curvedPath = root->val + left + right;
        ans = max(ans,max(straightPath,curvedPath));
        return straightPath;
    }
    int maxPathSum(TreeNode* root) {    
        solve(root);
        return ans;
    }
};