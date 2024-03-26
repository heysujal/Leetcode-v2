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

    
    
    void traverse(TreeNode* root, int level, map<int, int> &mp){
        if(!root){
            return;
        }

        if(mp.find(level) == mp.end()){
            mp[level]  = root->val;
        }
        traverse(root->right, level+1, mp);
        traverse(root->left, level+1, mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;  // level -> value
        traverse(root, 0, mp);
        vector<int> ans;
        for(auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};