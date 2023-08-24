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
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                auto hd = q.front().second.first;
                auto lvl = q.front().second.second;
                q.pop();
                mp[hd][lvl].insert(node->val);
                if(node->left)  q.push({node->left, {hd-1,lvl+1}});
                if(node->right)  q.push({node->right, {hd+1,lvl+1}});
            }
        }
        for(auto &p : mp){
            vector<int> v;
            for(auto &c : p.second){
                for(auto &ele : c.second){
                    v.push_back(ele);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};