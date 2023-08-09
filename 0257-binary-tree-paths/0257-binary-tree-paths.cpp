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
    void solve(TreeNode* root, string temp, vector<string> &ans){
        if(!root){
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if(!root->left and !root->right){
            ans.push_back(temp + to_string(root->val));
            return;
        }
        temp += to_string(root->val) + "->";
        if(root->left)
            solve(root->left,temp,ans);
        if(root->right)
            solve(root->right,temp,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,"",ans);
        return ans;
    }
};