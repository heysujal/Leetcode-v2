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
    map<TreeNode*, int> mp;
    int ans = 0;
    int getSum(TreeNode* root){
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int left = getSum(root->left);
        int right = getSum(root->right);
        return mp[root] = root->val + left + right;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        int lSum = getSum(root->left);
        int rSum = getSum(root->right);
        ans += abs(lSum-rSum);
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};