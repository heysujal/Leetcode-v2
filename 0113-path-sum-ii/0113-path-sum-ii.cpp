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
    void solve(TreeNode* root, int target,  vector<int> &path,vector<vector<int>> &ans){
        if(!root) return;
        target = target-root->val;
        path.push_back(root->val);
        if(!root->left and !root->right){
            if(target == 0){
                ans.push_back(path);
            }    
            path.pop_back();
            return;
        } 
        solve(root->left, target, path, ans);
        solve(root->right, target, path, ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, path, ans);
        return ans;
    }
};