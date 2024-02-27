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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(height(root->left), height(root->right));
    }
    int helper(TreeNode* root){
        if(!root)
            return 0;
        // Number of edges
        int left = helper(root->left);
        int right = helper(root->right);
        // int l = height(root->left)-1; (edges)
        // int r = height(root->right)-1; (edges)
        // int curved = 2 + l + r; (edges)
        int curved = height(root->left) + height(root->right); 
        int straight = max(left, right); 
        ans = max(ans, max(curved, straight));
        return straight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans == INT_MIN ? 0 : ans;
    }
};