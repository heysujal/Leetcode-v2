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
    int ans = 0;
    int dfs(TreeNode* root, int temp){
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return temp*10 + root->val;
        int left = dfs(root->left,temp*10 + root->val);
        int right = dfs(root->right,temp*10 + root->val); 
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};