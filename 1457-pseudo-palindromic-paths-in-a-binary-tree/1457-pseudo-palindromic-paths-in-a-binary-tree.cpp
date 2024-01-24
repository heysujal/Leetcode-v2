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
    int helper(TreeNode* root, int val){
        if(!root){
            return 0;
        } 
        val ^= (1 << (root->val));
        if(!root->left and !root->right){
            // now val should be a power of 2
            return (val & (val-1)) == 0;
        }
        int ans = 0;
        ans += helper(root->left, val);
        ans += helper(root->right, val);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int val = 0;
        return helper(root, val);
    }
};