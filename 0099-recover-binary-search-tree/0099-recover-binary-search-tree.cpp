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
    vector<int> in;
    int i = 0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        root->val = in[i++];
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(in.begin(), in.end());
        dfs(root);
    }
};