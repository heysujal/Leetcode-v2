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
        return !root ? 0 : 1 + max(height(root->left),height(root->right));
    }
    int ans;
    bool flag = true;
    void helper(TreeNode* root, int level){
        if(!root or !flag){
            return; 
        }
        if(level == 0 and flag){
            ans = root->val;
            flag = false;
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