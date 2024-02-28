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
    void helper(TreeNode* root, int level, map<int, int> &mp){
        if(!root){
            return; 
        }
        mp[level] = (root->val);
        helper(root->right, level + 1, mp);
        helper(root->left, level + 1, mp);
    }               
    int findBottomLeftValue(TreeNode* root) {
        map<int, int> mp; // level -> values;
        helper(root, 0, mp);
        auto it = mp.end();
        it--;
        return it->second;
    }
};