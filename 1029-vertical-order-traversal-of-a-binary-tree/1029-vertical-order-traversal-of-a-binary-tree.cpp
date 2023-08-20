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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        map<int,map<int,multiset<int>>> mp; // hd-> [lvl, [elements]]
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node = q.front().first;
            auto hd = q.front().second.first;
            auto lvl = q.front().second.second;
            q.pop();
            mp[hd][lvl].insert(node->val);
            if(node->left)
                q.push({node->left,{hd-1,lvl+1}});
            if(node->right)
                q.push({node->right,{hd+1,lvl+1}});
        }
        for(auto &_hdLvlElements : mp){
            vector<int> col;
            for(auto &lvlElements : _hdLvlElements.second){
                col.insert(col.end(), lvlElements.second.begin(), lvlElements.second.end());
            }
            v.push_back(col);
        }
        return v;
    }
};