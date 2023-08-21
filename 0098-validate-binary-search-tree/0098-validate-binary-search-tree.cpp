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
    bool solve(TreeNode* root, long mini, long maxi){
        if(!root) return true;
        // if(!root->left and !root->right) return true; // can'dd this bcoz we need to check
        // for leaf also if it is within the range or not.
        bool curr = root->val < maxi and root->val > mini;
        bool left = solve(root->left, mini, root->val);
        bool right = solve(root->right, root->val, maxi);
        return curr and left and right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};