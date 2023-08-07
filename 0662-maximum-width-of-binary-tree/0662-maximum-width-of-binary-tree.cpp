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
    int maxVal = 0;
    int levelOrderDFS(TreeNode* root,int level, long long idx, vector<pair<unsigned long long, unsigned long long>> &ans){
        if(!root)
            return 0;
        if(ans.size() == level)// creates a array for level
            ans.push_back({idx,idx}); // 
        ans[level].second = idx;
        unsigned long long left = levelOrderDFS(root->left,level+1,2ULL*idx,ans);
        unsigned long long right = levelOrderDFS(root->right,level+1,2ULL*idx+1,ans);
        return (int)max({ans[level].second-ans[level].first+1,left,right});
    }
 
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<unsigned long long,unsigned long long>> ans;
        return levelOrderDFS(root,0,0,ans);
    }
};