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
    int height(TreeNode* root){
        return !root ? 0 : 1 + height(root->left) + height(root->right);
    }
    int ans;
    void helper(TreeNode* root, int level){
        if(!root){
            return; 
        }
        if(level == 0){
            ans = root->val;
            return;
        }
        helper(root->left, level - 1);
        helper(root->right, level - 1);
    }               
    int findBottomLeftValue(TreeNode* root) {
        int level = height(root)-1;
        helper(root, level);
        return ans;
    }
};